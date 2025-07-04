#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <sys/wait.h>
#include <string.h>

#define MESSAGE_SIZE 32

int main() {
    char* inputMessage = (char *) malloc(sizeof(char) * MESSAGE_SIZE);
    printf("Enter the message of the day:\n");
    scanf("%31s", inputMessage);
    inputMessage[MESSAGE_SIZE - 1] = '\0';

    int sharedMemory = shmget(8752, sizeof(char) * MESSAGE_SIZE, 0);
    char* memoryMessage = (char *) shmat(sharedMemory, 0, 0);
    strcpy(memoryMessage, inputMessage);

    free(inputMessage);
    return 0;
}
