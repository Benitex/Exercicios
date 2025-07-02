#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <sys/wait.h>

#define MESSAGE_SIZE 32

int main() {
    int sharedMemory = shmget(8752, sizeof(char) * MESSAGE_SIZE, 0);
    char* memoryMessage = (char *) shmat(sharedMemory, 0, 0);
    printf("%s\n", memoryMessage);
}
