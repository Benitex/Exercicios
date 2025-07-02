// Benito André Pepe - 2311720

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <limits.h>

#define PROCESS_AMOUNT 4
#define PHYSICAL_MEMORY_PAGES_AMOUNT 16
#define VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS 32
#define WORKING_SET_WINDOW 3

typedef enum bool {
    false = 0,
    true = 1
} Bool;

/// A frame in physical memory.
typedef struct memoryFrame {
    int virtualPageNumber;
    int process;
} MemoryFrame;

typedef struct pageTable {
    Bool isInitialized;
    Bool isInMemory;
    Bool isModified; // Indicates if the page was written to at least once.

    // NRU
    Bool wasRecentlyReferenced;
    Bool wasRecentlyModified;

    // LRU
    unsigned int ageBitmap;

    // Working Set
    int lastAccessRound;
} PageTable;

/// Reprents a single try to access a page in memory.
typedef struct memoryAccess {
    int virtualPageNumber;
    Bool isWrite;
} MemoryAccess;

typedef struct pageFault {
    int processThatReceivedPage;
    int processThatLostPage;
    Bool causedWriteInModifiedPage;
} PageFault;

void createAccessTables(int accessesAmount);
void manageMemory(char *algorithm, int roundsAmount);
void streamMemoryAccesses(int processNumber, int *pipe);
int getAvailableFrame(MemoryFrame *memoryFrames);
int selectNotRecentlyUsedFrame(MemoryFrame *memoryFrames, PageTable processesPageTables[PROCESS_AMOUNT][VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS]);
int selectFrameBySecondChance(MemoryFrame *memoryFrames, PageTable processesPageTables[PROCESS_AMOUNT][VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS], int framesQueue[PHYSICAL_MEMORY_PAGES_AMOUNT]);
int selectLeastRecentlyUsedFrame(int process, MemoryFrame *memoryFrames, PageTable processesPageTables[PROCESS_AMOUNT][VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS]);
int selectFrameByWorkingSet(int process, int currentRound, MemoryFrame *memoryFrames, PageTable processesPageTables[PROCESS_AMOUNT][VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS]);
void printResults(char* algorithm, int roundsAmount, PageFault* pageFaults, int pageFaultsAmount, PageTable processesPageTables[PROCESS_AMOUNT][VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS]);

int main(int argc, char *argv[]) {
    if (argc > 4 || argc < 2) {
        fprintf(stderr, "Usage: %s <algorithm> <rounds_amount>\n", argv[0]);
        return 1;
    } else if (argc == 4) {
        int accessesAmount = atoi(argv[3]);
        createAccessTables(accessesAmount);
    }

    char* algorithm = argv[1];
    for (int i = 0; algorithm[i]; i++) {
        algorithm[i] = toupper(algorithm[i]);
    }
    
    int roundsAmount = atoi(argv[2]);
    manageMemory(algorithm, roundsAmount);

    return 0;
}

void manageMemory(char *algorithm, int roundsAmount) {
    int pipes[PROCESS_AMOUNT][2];
    pid_t children[PROCESS_AMOUNT];

    // Create child processes
    for (int processIndex = 0; processIndex < PROCESS_AMOUNT; processIndex++) {
        if (pipe(pipes[processIndex]) < 0) {
            perror("Pipe creation failed");
            exit(3);
        }

        pid_t child = fork();
        if (child < 0) {
            perror("Fork failed");
            exit(2);
        } else if (child > 0) {
            // Parent process
            close(pipes[processIndex][1]);
            children[processIndex] = child;
            continue;
        } else {
            raise(SIGSTOP);
            streamMemoryAccesses(processIndex, pipes[processIndex]);
            exit(0);
        }
    }

    MemoryFrame memoryFrames[PHYSICAL_MEMORY_PAGES_AMOUNT];
    for (int i = 0; i < PHYSICAL_MEMORY_PAGES_AMOUNT; i++) {
        memoryFrames[i].virtualPageNumber = -1;
        memoryFrames[i].process = -1;
    }

    PageTable processesPageTables[PROCESS_AMOUNT][VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS];
    for (int process = 0; process < PROCESS_AMOUNT; process++) {
        for (int page = 0; page < VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS; page++) {
            processesPageTables[process][page].isInitialized = false;
            processesPageTables[process][page].isInMemory = false;
            processesPageTables[process][page].isModified = false;

            // NRU
            processesPageTables[process][page].wasRecentlyReferenced = false;
            processesPageTables[process][page].wasRecentlyModified = false;
        }
    }

    PageFault *pageFaults = (PageFault *) malloc(sizeof(PageFault) * roundsAmount * PROCESS_AMOUNT);
    int pageFaultsAmount = 0;

    int round = 0;
    int currentProcess = 0;
    MemoryAccess currentAccess;

    // Second Chance
    int framesQueue[PHYSICAL_MEMORY_PAGES_AMOUNT];
    int queueLength = 0;

    // Round robin scheduling
    while (round < roundsAmount) {
        kill(children[currentProcess], SIGCONT);
        read(pipes[currentProcess][0], &currentAccess, sizeof(MemoryAccess));
        kill(children[currentProcess], SIGSTOP);

        PageTable *currentPageTable = &processesPageTables[currentProcess][currentAccess.virtualPageNumber];
        if (!currentPageTable->isInitialized) {
            currentPageTable->isInitialized = true;
        }

        // Bits for the selection algorithms
        currentPageTable->wasRecentlyReferenced = true;
        if (strcmp("NRU", algorithm) == 0 && currentAccess.isWrite) {
            currentPageTable->wasRecentlyModified = true;
        }

        if (!currentPageTable->isInMemory) { // A new memory page allocation is necessary
            int availableFrameIndex = getAvailableFrame(memoryFrames);

            if (availableFrameIndex >= 0) {
                memoryFrames[availableFrameIndex].process = currentProcess;
                memoryFrames[availableFrameIndex].virtualPageNumber = currentAccess.virtualPageNumber;

                currentPageTable->isInMemory = true;
                currentPageTable->isModified = currentAccess.isWrite;

                if (strcmp(algorithm, "SC") == 0) {
                    framesQueue[queueLength] = availableFrameIndex;
                    queueLength++;
                } else if (strcmp(algorithm, "WS") == 0) {
                    currentPageTable->lastAccessRound = round;
                } 
            } else { // Page fault
                int frameToReplace;
                if (strcmp(algorithm, "NRU") == 0) {
                    frameToReplace = selectNotRecentlyUsedFrame(memoryFrames, processesPageTables);
                } else if (strcmp(algorithm, "LRU") == 0) {
                    frameToReplace = selectLeastRecentlyUsedFrame(currentProcess, memoryFrames, processesPageTables);
                } else if (strcmp(algorithm, "SC") == 0) {
                    frameToReplace = selectFrameBySecondChance(memoryFrames, processesPageTables, framesQueue);
                } else if (strcmp(algorithm, "WS") == 0) {
                    frameToReplace = selectFrameByWorkingSet(currentProcess, round, memoryFrames, processesPageTables);
                } else {
                    fprintf(stderr, "%s is not a valid algorithm name, please use NRU, SC, LRU or WS.\n", algorithm);
                    exit(1);
                }

                PageTable *pageBeingReplaced = &processesPageTables[memoryFrames[frameToReplace].process][memoryFrames[frameToReplace].virtualPageNumber];

                currentPageTable->isInMemory = true;
                pageBeingReplaced->isInMemory = false;

                if (currentAccess.isWrite) {
                    currentPageTable->isModified = true;
                }

                // Registering the page fault
                pageFaults[pageFaultsAmount].processThatReceivedPage = currentProcess;
                pageFaults[pageFaultsAmount].processThatLostPage = memoryFrames[frameToReplace].process;
                // If the page being replaced was modified, it needs to be written to swap
                pageFaults[pageFaultsAmount].causedWriteInModifiedPage = pageBeingReplaced->isModified;
                pageFaultsAmount++;

                // Replacing the frame
                memoryFrames[frameToReplace].process = currentProcess;
                memoryFrames[frameToReplace].virtualPageNumber = currentAccess.virtualPageNumber;

                // Resetting the "M" bit from NRU
                if (strcmp(algorithm, "NRU") == 0) {
                    if (pageBeingReplaced->isModified) {
                        pageBeingReplaced->wasRecentlyModified = false;
                    }
                } else if (strcmp(algorithm, "WS") == 0) {
                    currentPageTable->lastAccessRound = round;
                }
            }
        }

        // Moving to the next process (and round)
        currentProcess++;
        if (currentProcess >= PROCESS_AMOUNT) {
            currentProcess = 0;
            round++;

            // Resetting the "R bit" from NRU
            if (strcmp(algorithm, "NRU") == 0) {
                for (int process = 0; process < PROCESS_AMOUNT; process++) {
                    for (int page = 0; page < VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS; page++) {
                        processesPageTables[process][page].wasRecentlyReferenced = false;
                    }
                }
            } else if (strcmp(algorithm, "LRU") == 0) {
                for (int process = 0; process < PROCESS_AMOUNT; process++) {
                    for (int page = 0; page < VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS; page++) {
                        processesPageTables[process][page].ageBitmap >>= 1;

                        if (processesPageTables[process][page].wasRecentlyReferenced) {
                            processesPageTables[process][page].ageBitmap |= 1 << ((sizeof(unsigned int) * CHAR_BIT) - 1);
                            processesPageTables[process][page].wasRecentlyReferenced = false;
                        }
                    }
                }
            } else if (strcmp(algorithm, "WS") == 0) {
                for (int i = 0; i < PHYSICAL_MEMORY_PAGES_AMOUNT; i++) {
                    PageTable *pageTable = &processesPageTables[memoryFrames[i].process][memoryFrames[i].virtualPageNumber];

                    if (pageTable->wasRecentlyReferenced) {
                        pageTable->lastAccessRound = round;
                        pageTable->wasRecentlyReferenced = false;
                    }
                }
            }
        }
    }

    for (int i = 0; i < PROCESS_AMOUNT; i++) {
        close(pipes[i][0]);
    }

    printResults(algorithm, roundsAmount, pageFaults, pageFaultsAmount, processesPageTables);
    free(pageFaults);
}

/// Returns the index of the next available frame in memory.
/// If no frame is available, returns -1.
int getAvailableFrame(MemoryFrame *memoryFrames) {
    for (int i = 0; i < PHYSICAL_MEMORY_PAGES_AMOUNT; i++) {
        if (memoryFrames[i].process == -1 && memoryFrames[i].virtualPageNumber == -1) {
            return i; 
        }
    }

    return -1;
}

int selectNotRecentlyUsedFrame(MemoryFrame *memoryFrames, PageTable processesPageTables[PROCESS_AMOUNT][VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS]) {
    int notReferencedButModified = -1;
    int referencedButNotModified = -1;
    int referencedAndModified = -1;

    for (int i = 0; i < PHYSICAL_MEMORY_PAGES_AMOUNT; i++) {
        PageTable *pageTable = &processesPageTables[memoryFrames[i].process][memoryFrames[i].virtualPageNumber];

        if (!pageTable->wasRecentlyReferenced && !pageTable->wasRecentlyModified) {
            return i;
        } else if (notReferencedButModified == -1 && !pageTable->wasRecentlyReferenced && pageTable->wasRecentlyModified) {
            notReferencedButModified = i;
        } else if (referencedButNotModified == -1 && pageTable->wasRecentlyReferenced && !pageTable->wasRecentlyModified) {
            referencedButNotModified = i;
        } else if (referencedAndModified == -1 && pageTable->wasRecentlyReferenced && pageTable->wasRecentlyModified) {
            referencedAndModified = i;
        }
    }

    if (notReferencedButModified != -1) {
        return notReferencedButModified;
    } else if (referencedButNotModified != -1) {
        return referencedButNotModified;
    } else {
        return referencedAndModified;
    }
}

int selectFrameBySecondChance(MemoryFrame *memoryFrames, PageTable processesPageTables[PROCESS_AMOUNT][VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS], int framesQueue[PHYSICAL_MEMORY_PAGES_AMOUNT]) {
    for (int i = 0; i < PHYSICAL_MEMORY_PAGES_AMOUNT; i++) {
        int frameIndex = framesQueue[i];
        PageTable *pageTable = &processesPageTables[memoryFrames[frameIndex].process][memoryFrames[frameIndex].virtualPageNumber];

        if (pageTable->wasRecentlyReferenced) {
            pageTable->wasRecentlyReferenced = false;
        } else {
            // Remove the frame from the queue
            for (int otherFrameIndex = i; otherFrameIndex < PHYSICAL_MEMORY_PAGES_AMOUNT; otherFrameIndex++) {
                framesQueue[otherFrameIndex] = framesQueue[otherFrameIndex + 1];
            }

            // Add the frame to the end of the queue
            framesQueue[PHYSICAL_MEMORY_PAGES_AMOUNT - 1] = frameIndex;
            return frameIndex;
        }
    }

    // If all frames were recently referenced, return the first one
    return framesQueue[0];
}

int selectLeastRecentlyUsedFrame(int process, MemoryFrame *memoryFrames, PageTable processesPageTables[PROCESS_AMOUNT][VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS]) {
    int selectedFrame = -1;
    int oldestAge = 0;

    for (int i = 0; i < PHYSICAL_MEMORY_PAGES_AMOUNT; i++) {
        // Ignore frames from other processes for local substitution
        if (process != memoryFrames[i].process) continue;

        PageTable *pageTable = &processesPageTables[memoryFrames[i].process][memoryFrames[i].virtualPageNumber];
        if (selectedFrame == -1 || pageTable->ageBitmap < oldestAge) {
            selectedFrame = i;
            oldestAge = pageTable->ageBitmap;
        }
    }

    return selectedFrame;
}

int selectFrameByWorkingSet(int process, int currentRound, MemoryFrame *memoryFrames, PageTable processesPageTables[PROCESS_AMOUNT][VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS]) {
    int selectedFrame = -1;
    int oldestRound = 0;

    for (int i = 0; i < PHYSICAL_MEMORY_PAGES_AMOUNT; i++) {
        // Ignore frames from other processes for local substitution
        if (process != memoryFrames[i].process) continue;

        PageTable *pageTable = &processesPageTables[memoryFrames[i].process][memoryFrames[i].virtualPageNumber];
        int age = currentRound - pageTable->lastAccessRound;
        if (age > WORKING_SET_WINDOW) {
            if (age > oldestRound || selectedFrame == -1) {
                selectedFrame = i;
                oldestRound = age;
            }
        } 
    }

    // If all frames are within the working set window, I just select the oldest one
    if (selectedFrame == -1) {
        for (int i = 0; i < PHYSICAL_MEMORY_PAGES_AMOUNT; i++) {
            if (process != memoryFrames[i].process) continue;

            PageTable *pageTable = &processesPageTables[memoryFrames[i].process][memoryFrames[i].virtualPageNumber];
            int age = currentRound - pageTable->lastAccessRound;
            if (age > oldestRound || selectedFrame == -1) {
                selectedFrame = i;
                oldestRound = age;
            }
        }
    }

    return selectedFrame;
}

void streamMemoryAccesses(int processNumber, int *pipe) {
    close(pipe[0]);

    char fileName[15] = "acessos_p0.txt";
    fileName[9] = ++processNumber + '0';
    FILE *file = fopen(fileName, "r");

    int pageNumber;
    char accessType;
    while (fscanf(file, "%d %c", &pageNumber, &accessType) == 2) {
        MemoryAccess access;
        access.virtualPageNumber = pageNumber;
        access.isWrite = (accessType == 'W') ? true : false;

        write(pipe[1], &access, sizeof(MemoryAccess));
    }

    close(pipe[1]);
    fclose(file);
}

void createAccessTables(int accessesAmount) {
    FILE *file;

    srand(getpid());
    for (int process = 1; process <= PROCESS_AMOUNT; process++) {
        char fileName[15] = "acessos_p0.txt";
        fileName[9] = process + '0';
        file = fopen(fileName, "w");

        for (int i = 0; i < accessesAmount; i++) {
            int page = rand() % VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS;
            Bool isRead = rand() % 2;
            fprintf(file, "%02d %c\n", page, isRead ? 'R' : 'W');
        }

        fclose(file);
    }
}

void printResults(char* algorithm, int roundsAmount, PageFault* pageFaults, int pageFaultsAmount, PageTable processesPageTables[PROCESS_AMOUNT][VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS]) {
    printf("Algoritmo de Substituição %s\n", algorithm);
    printf("Rodadas executadas: %d\n", roundsAmount);

    printf("\nPage faults (%d)\n", pageFaultsAmount);

    int swappedPages = 0;
    for (int i = 0; i < pageFaultsAmount; i++) {
        if (pageFaults[i].causedWriteInModifiedPage) {
            swappedPages++;
        }
    }
    printf("Total de páginas escritas na área de swap: %d\n", swappedPages);

    for (int i = 0; i < pageFaultsAmount; i++) {
        printf(
            "Processo %d causou page fault removendo página do processo %d.\n",
            pageFaults[i].processThatReceivedPage,
            pageFaults[i].processThatLostPage
        );
        if (pageFaults[i].causedWriteInModifiedPage) {
            printf("O page fault ocasionou escrita em uma página modificada na área de swap.\n");
        }
    }

    printf("\nTabelas de páginas dos processos:\n");
    for (int process = 0; process < PROCESS_AMOUNT; process++) {
        printf("\nProcesso %d:\n", process);
        for (int page = 0; page < VIRTUAL_MEMORY_PAGES_AMOUNT_PER_PROCESS; page++) {
            PageTable *pageTable = &processesPageTables[process][page];

            if (!pageTable->isInitialized) continue;

            printf("Página %02d: ", page);
            printf("Na memória: %s, ", pageTable->isInMemory ? "Sim" : "Não");
            printf("Modificada: %s\n", pageTable->isModified ? "Sim" : "Não");
        }
    }
}
