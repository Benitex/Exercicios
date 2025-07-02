#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <sys/wait.h>

int main() {
    int m1 = shmget(8852, sizeof(int), 0);
    int *value1 = (int *) shmat(m1, NULL, 0);
    sleep(rand() % 3);
    *value1 = 3;
    printf("Value 3 set to m1\n");
    return 0;
}
