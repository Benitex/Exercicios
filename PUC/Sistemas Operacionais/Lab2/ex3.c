#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <sys/wait.h>

#define PROCESS_AMOUNT 4
#define ARRAY_SIZE 200

int main() {
    int sharedMemory = shmget(IPC_PRIVATE, sizeof(int) * ARRAY_SIZE, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    int *array = (int *) shmat(sharedMemory, 0, 0);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i;
    }

    int lookingFor = 199;

    for (int process = 0; process < PROCESS_AMOUNT; process++) {
        int child = fork();
        if (child < 0) exit(1);

        if (child == 0) {
            int startingIndex = process * (ARRAY_SIZE / PROCESS_AMOUNT);
            for (int i = 0; i < ARRAY_SIZE / PROCESS_AMOUNT; i++) {
                if (array[startingIndex + i] == lookingFor) {
                    printf("Found %d in process %d at index %d\n", lookingFor, process, startingIndex + i);
                    exit(0);
                }
            }
            exit(0);
        } else {
            waitpid(-1, NULL, 0);
        }
    }

    shmdt(array);
    shmctl(sharedMemory, IPC_RMID, 0);
}
