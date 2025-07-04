// Benito André Pepe - 2311720

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>

#define AIRPLANE_X_SPEED 0.05
#define AIRPORT_X 0.5
#define AIRPORT_Y 0.5
#define AIRPLANES_MEMORY_SEGMENT_KEY 8952
#define PROCESSES_MEMORY_SEGMENT_KEY 8752

typedef enum bool {
    FALSE = 0,
    TRUE = 1,
} Bool;

typedef enum direction {
    WEST = 0,
    EAST = 1,
} Direction;

typedef enum landingStrip {
    W3 = 3,
    E6 = 6,
    W18 = 18,
    E27 = 27,
} LandingStrip;

typedef enum landingStatus {
    APPROACHING = 0,
    IN_AIR = 1,
    LANDED = 2,
    STOPPED_LANDING = 3,
} LandingStatus;

typedef struct airplane {
    float x;
    float y;
    float speed;
    Direction comingDirection;
    LandingStrip preferredStrip;
    LandingStatus landingStatus;
} Airplane;

void loadAirspace();
float getYSpeed(Airplane airplane);
void manageAirplanes();
void printAirplanesStatus(Airplane *airplanes);
void reduceSpeed(int signal);
void changeStrip(int signal);
Bool areAirplanesInCollisionRoute(Airplane airplane1, Airplane airplane2, Bool considerStrips, Bool checkIfTheyAreColliding);
Bool canAvoidCollisionByChangingStrip(Airplane *airplanes, int airplaneIndex);
void quitProgram(int signal);
void pauseProgram(int signal);

int numberOfAirplanes;
int messageDurationSeconds;
Bool isPaused = FALSE;

int main(int argc, char const *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <number_of_airplanes> <message_duration_seconds>\n", argv[0]);
        return 1;
    }

    numberOfAirplanes = atoi(argv[1]);
    messageDurationSeconds = atoi(argv[2]);

    pid_t child = fork();
    if (child < 0) {
        perror("Fork failed");
        return 2;
    } else if (child == 0) {
        loadAirspace();
    } else {
        signal(SIGINT, quitProgram);
        signal(SIGTSTP, pauseProgram);
        usleep(500000); // Delay for the child processes to assign their pids to the shared memory
        manageAirplanes();
    }

    return 0;
}

/// Creates child processes that simulate the airplanes in the airspace, sets up their signal handlers, 
/// initializes their values, and assigns shared memory segments to them.
void loadAirspace() {
    int airplanesMemory = shmget(AIRPLANES_MEMORY_SEGMENT_KEY, sizeof(Airplane) * numberOfAirplanes, IPC_CREAT | S_IRUSR | S_IWUSR);
    Airplane *airplanes = (Airplane *) shmat(airplanesMemory, 0, 0);

    int processesMemory = shmget(PROCESSES_MEMORY_SEGMENT_KEY, sizeof(pid_t) * numberOfAirplanes, IPC_CREAT | S_IRUSR | S_IWUSR);
    pid_t *processes = (pid_t *) shmat(processesMemory, 0, 0);

    signal(SIGUSR1, reduceSpeed);
    signal(SIGUSR2, changeStrip);

    for (int i = 0; i < numberOfAirplanes; i++) {
        pid_t child = fork();
        if (child < 0) {
            perror("Fork failed");
            exit(1);
        } else if (child != 0) { // Parent process
            continue;
        }

        processes[i] = getpid();

        // Default values before arriving in the airspace
        airplanes[i].speed = 0;
        airplanes[i].x = -1;
        airplanes[i].y = -1;
        airplanes[i].landingStatus = APPROACHING;

        raise(SIGSTOP);

        srand(getpid()); // Random seed for each child process
        sleep(rand() % 3); // Delay until the plane enters the airspace

        airplanes[i].landingStatus = IN_AIR;
        airplanes[i].comingDirection = rand() % 2; // Directly converted to the enum, 0 = WEST, 1 = EAST

        if (airplanes[i].comingDirection == WEST) {
            // If the result of rand can be 0 or 1. If it's 0, the strip will be W18, otherwise it'll be W3
            airplanes[i].preferredStrip = rand() % 2 ? W3 : W18;
        } else {
            // If the result of rand can be 0 or 1. If it's 0, the strip will be E27, otherwise it'll be E6
            airplanes[i].preferredStrip = rand() % 2  ? E6 : E27;
        }

        // Because they can only start on the edges of the map, the enum values are enough to determine the x coordinate
        airplanes[i].x = airplanes[i].comingDirection;
        airplanes[i].y = rand() % 101 / 100.0;
        airplanes[i].speed = AIRPLANE_X_SPEED;
        float ySpeed = getYSpeed(airplanes[i]);

        raise(SIGSTOP);

        // Movement simulation
        while (TRUE) {
            if (airplanes[i].x != AIRPORT_X) {
                if (airplanes[i].comingDirection == WEST) {
                    airplanes[i].x += airplanes[i].speed;
                    if (airplanes[i].x >= AIRPORT_X) airplanes[i].x = AIRPORT_X;
                } else {
                    airplanes[i].x -= airplanes[i].speed;
                    if (airplanes[i].x <= AIRPORT_X) airplanes[i].x = AIRPORT_X;
                }    
            }

            if (airplanes[i].y != AIRPORT_Y) {
                if (airplanes[i].y < AIRPORT_Y) {
                    airplanes[i].y += (airplanes[i].speed < AIRPLANE_X_SPEED) ? 0 : ySpeed;
                    if (airplanes[i].y >= AIRPORT_Y) airplanes[i].y = AIRPORT_Y;
                } else {
                    airplanes[i].y -= (airplanes[i].speed < AIRPLANE_X_SPEED) ? 0 : ySpeed;
                    if (airplanes[i].y <= AIRPORT_Y) airplanes[i].y = AIRPORT_Y;
                }
            }

            airplanes[i].speed = AIRPLANE_X_SPEED; // Resets the speed after a speed reduction

            if (airplanes[i].x == AIRPORT_X && airplanes[i].y == AIRPORT_Y) {
                airplanes[i].speed = 0;
                airplanes[i].landingStatus = LANDED;
                shmdt(airplanes);
                shmdt(processes);
                exit(0);
            }

            raise(SIGSTOP);
        }
    }
}

/// Calculates the speed of the airplane in the y direction.
/// The speed is calculated based on the distance to the airport and the time it takes to reach it in the X axis.
/// ex: If the airplane starts at (0.0, 0.0), the distance to the airport is 0.5,
/// the resulting speed is 0.5 / 10 = 0.05. 10 * 0.05 = 0.5
float getYSpeed(Airplane airplane) {
    float difference;
    if (airplane.y > AIRPORT_Y) {
        difference = airplane.y - AIRPORT_Y;
    } else {
        difference = AIRPORT_Y - airplane.y;
    }

    // The plane will always take 10 steps to reach the airport, because the X speed is constant
    // So, dividing the difference by 10 will lead to the speed
    return difference / 10.0;
}

/// Controls the aiplanes processes and their tries to avoid collisions.
void manageAirplanes() {
    int memorySegment = shmget(AIRPLANES_MEMORY_SEGMENT_KEY, sizeof(Airplane) * numberOfAirplanes, IPC_CREAT | S_IRUSR | S_IWUSR);
    Airplane *airplanes = (Airplane *) shmat(memorySegment, 0, 0);

    int processesMemory = shmget(PROCESSES_MEMORY_SEGMENT_KEY, sizeof(pid_t) * numberOfAirplanes, IPC_CREAT | S_IRUSR | S_IWUSR);
    pid_t *processes = (pid_t *) shmat(processesMemory, 0, 0);

    int currentAirplaneTurn = 0;
    Bool allPlanesArrived = FALSE;

    while (!allPlanesArrived) {
        Bool hadToCancelLanding = FALSE;

        // Airplanes with lower indexes stop for those that might collide
        for (int otherAriplane = currentAirplaneTurn + 1; otherAriplane < numberOfAirplanes; otherAriplane++) {
            // Check for leaving the airspace
            if (areAirplanesInCollisionRoute(airplanes[currentAirplaneTurn], airplanes[otherAriplane], TRUE, TRUE)) {
                kill(processes[currentAirplaneTurn], SIGKILL); // Stop the landing if they have a high risk of collision
                hadToCancelLanding = TRUE;
                airplanes[currentAirplaneTurn].landingStatus = STOPPED_LANDING;

                printf("Airplane %d will leave the airspace to avoid collision with airplane %d.\n", currentAirplaneTurn, otherAriplane);

                if (messageDurationSeconds > 0) sleep(messageDurationSeconds);
                break;
            }

            // Check for avoiding collisions
            if (areAirplanesInCollisionRoute(airplanes[currentAirplaneTurn], airplanes[otherAriplane], TRUE, FALSE)) {
                if (canAvoidCollisionByChangingStrip(airplanes, currentAirplaneTurn)) {
                    kill(processes[currentAirplaneTurn], SIGUSR2);
                    printf("Airplane %d will change strip to avoid collision with airplane %d.\n", currentAirplaneTurn, otherAriplane);
                } else {
                    kill(processes[currentAirplaneTurn], SIGUSR1);
                    printf("Airplane %d will reduce speed to avoid collision with airplane %d.\n", currentAirplaneTurn, otherAriplane);
                }

                if (messageDurationSeconds > 0) sleep(messageDurationSeconds);
                break;
            }
        }
        if (!hadToCancelLanding) kill(processes[currentAirplaneTurn], SIGCONT);

        // Stop the previous process
        int previousAirplaneTurn = currentAirplaneTurn - 1;
        if (previousAirplaneTurn < 0) {
            previousAirplaneTurn = numberOfAirplanes - 1;
        }

        if (previousAirplaneTurn == currentAirplaneTurn - 1) {
            kill(processes[previousAirplaneTurn], SIGSTOP);
        }
        usleep(500000);

        printAirplanesStatus(airplanes);

        // Choose next (not finished) process
        Bool decidedNextAirplane = FALSE;

        int nextAirplaneTurn = currentAirplaneTurn + 1;
        if (nextAirplaneTurn >= numberOfAirplanes) {
            nextAirplaneTurn = 0;
        }

        while (!decidedNextAirplane || allPlanesArrived) {
            LandingStatus status = airplanes[nextAirplaneTurn].landingStatus;
            if (status == IN_AIR || status == APPROACHING) {
                decidedNextAirplane = TRUE;
            } else {
                nextAirplaneTurn++;
            }
            if (nextAirplaneTurn >= numberOfAirplanes) {
                nextAirplaneTurn = 0;
            }

            if (nextAirplaneTurn == currentAirplaneTurn && airplanes[currentAirplaneTurn].landingStatus == LANDED) {
                allPlanesArrived = TRUE;
                break;
            }
        }
        currentAirplaneTurn = nextAirplaneTurn;

        while (isPaused) {
            usleep(100000);
        }
    }

    shmdt(airplanes);
    shmdt(processes);
    shmctl(memorySegment, IPC_RMID, NULL);
    shmctl(processesMemory, IPC_RMID, NULL);
}

void printAirplanesStatus(Airplane *airplanes) {
    system("clear");

    for (int i = 0; i < numberOfAirplanes; i++) {
        if (airplanes[i].landingStatus == APPROACHING) {
            printf("Airplane %d: Not in airspace yet\n", i);
        } else if (airplanes[i].landingStatus == STOPPED_LANDING) {
            printf("Airplane %d - had to cancel landing\n", i);
        } else {
            char *strip;
            if (airplanes[i].comingDirection == WEST) {
                strip = airplanes[i].preferredStrip == W3 ? "W3" : "W18";
            } else {
                strip = airplanes[i].preferredStrip == E6 ? "E6" : "E27";
            }

            if (airplanes[i].landingStatus == LANDED) {
                printf("Airplane %d - landed at %s\n", i, strip);
            } else if (airplanes[i].landingStatus == IN_AIR) {
                char *direction = airplanes[i].comingDirection == WEST ? "WEST" : "EAST";
                printf("Airplane %d - position: (%.2f, %.2f), coming from: %s, strip: %s\n", i, airplanes[i].x, airplanes[i].y, direction, strip);
            }
        }
    }

    putchar('\n');
}

void reduceSpeed(int signal) {
    pid_t processId = getpid();

    int processesMemory = shmget(PROCESSES_MEMORY_SEGMENT_KEY, sizeof(pid_t) * numberOfAirplanes, IPC_CREAT | S_IRUSR | S_IWUSR);
    pid_t *processes = (pid_t *) shmat(processesMemory, 0, 0);

    int planeIndex;
    for (int i = 0; i < numberOfAirplanes; i++) {
        if (processes[i] == processId) {
            planeIndex = i;
            break;
        }
    }
    shmdt(processes);

    int airplanesMemory = shmget(AIRPLANES_MEMORY_SEGMENT_KEY, sizeof(Airplane) * numberOfAirplanes, IPC_CREAT | S_IRUSR | S_IWUSR);
    Airplane *airplanes = (Airplane *) shmat(airplanesMemory, 0, 0);

    if (airplanes[planeIndex].speed > 0) {
        airplanes[planeIndex].speed = 0;
    } else {
        airplanes[planeIndex].speed = AIRPLANE_X_SPEED;
    }
}

void changeStrip(int signal) {
    pid_t processId = getpid();

    int processesMemory = shmget(PROCESSES_MEMORY_SEGMENT_KEY, sizeof(pid_t) * numberOfAirplanes, IPC_CREAT | S_IRUSR | S_IWUSR);
    pid_t *processes = (pid_t *) shmat(processesMemory, 0, 0);

    int planeIndex;
    for (int i = 0; i < numberOfAirplanes; i++) {
        if (processes[i] == processId) {
            planeIndex = i;
            break;
        }
    }
    shmdt(processes);

    int airplanesMemory = shmget(AIRPLANES_MEMORY_SEGMENT_KEY, sizeof(Airplane) * numberOfAirplanes, IPC_CREAT | S_IRUSR | S_IWUSR);
    Airplane *airplanes = (Airplane *) shmat(airplanesMemory, 0, 0);

    if (airplanes[planeIndex].comingDirection == WEST) {
        if (airplanes[planeIndex].preferredStrip == W3) {
            airplanes[planeIndex].preferredStrip = W18;
        } else {
            airplanes[planeIndex].preferredStrip = W3;
        }
    } else {
        if (airplanes[planeIndex].preferredStrip == E6) {
            airplanes[planeIndex].preferredStrip = E27;
        } else {
            airplanes[planeIndex].preferredStrip = E6;
        }
    }
}

/// Checks if, given two airplanes, they could collide in the airspace soon.
/// ex: If A and B are in the same strip, and A is at (0.55, 0.55) and B is at (0.6, 0.6), they are in collision route.
/// If checkIfTheyAreColliding is true, the function will check if they are already colliding instead.
/// If considerStrips is true, the function will ignore the airplanes that are on different strips.
/// ex: If A is on W3 and B is on W18, they are not in collision route.
Bool areAirplanesInCollisionRoute(Airplane airplane1, Airplane airplane2, Bool considerStrips, Bool checkIfTheyAreColliding) {
    float range = 0.2; // 0.15 is the minimum, + 0.5 from the future position
    if (checkIfTheyAreColliding) {
        range = 0.1;
    }

    if (airplane1.landingStatus != IN_AIR || airplane2.landingStatus != IN_AIR) {
        return FALSE;
    }

    if (considerStrips && (airplane1.preferredStrip != airplane2.preferredStrip)) {
        return FALSE; // Airplanes on different strips cannot collide
    }

    float xDistance, yDistance;
    if (airplane1.x > airplane2.x) {
        xDistance = airplane1.x - airplane2.x;
    } else {
        xDistance = airplane2.x - airplane1.x;
    }

    if (airplane1.y > airplane2.y) {
        yDistance = airplane1.y - airplane2.y;
    } else {
        yDistance = airplane2.y - airplane1.y;
    }

    if (xDistance <= range && yDistance <= range) {
        return TRUE;
    }

    return FALSE;
}

// Checks if a strip change is enough to avoid a collision.
// By checking how many airplanes could collide with the airplane at airplaneIndex.
// ex: if there are 3 airplanes that could collide, at least one of them would need to slow down to avoid the collision.
//     but if there are only 2 airplanes, one of them could simply change strip and avoid the collision.
Bool canAvoidCollisionByChangingStrip(Airplane *airplanes, int airplaneIndex) {
    int numberOfAirplanesThatCouldCollide = 0;
    for (int i = 0; i < numberOfAirplanes; i++) {
        if (i == airplaneIndex) continue;

        if (areAirplanesInCollisionRoute(airplanes[airplaneIndex], airplanes[i], FALSE, FALSE)) {
            numberOfAirplanesThatCouldCollide++;
        }
    }

    // If the airplane could collide with only another one, a strip change is enough to avoid the collision
    return numberOfAirplanesThatCouldCollide <= 1;
}

void quitProgram(int signal) {
    int memorySegment = shmget(AIRPLANES_MEMORY_SEGMENT_KEY, sizeof(Airplane) * numberOfAirplanes, IPC_CREAT | S_IRUSR | S_IWUSR);
    shmctl(memorySegment, IPC_RMID, NULL);

    int processesMemory = shmget(PROCESSES_MEMORY_SEGMENT_KEY, sizeof(pid_t) * numberOfAirplanes, IPC_CREAT | S_IRUSR | S_IWUSR);
    shmctl(processesMemory, IPC_RMID, NULL);

    printf("\nEnding program...\n");

    exit(0);
}

void pauseProgram(int signal) {
    if (isPaused) {
        printf("\nResuming program...\n");
        isPaused = FALSE;
    } else {
        printf("\nPausing program...\n");
        isPaused = TRUE;
    }
}
