#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <sys/wait.h>

int main() {
    int m1 = shmget(8852, sizeof(int), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    int *value1 = (int *) shmat(m1, NULL, 0);
    *value1 = 0;
    int m2 = shmget(8952, sizeof(int), IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    int *value2 = (int *) shmat(m2, NULL, 0);
    *value2 = 0;

    char *argv[] = {NULL};

    int child1 = fork();
    if (child1 == 0) {
        execv("./p1", argv);
        exit(0);
    }

    int child2 = fork();
    if (child2 == 0) {
        execv("./p2", argv);
        exit(0);
    }

    while (1 < 2) {
        if (*value1 != 0 && *value2 != 0) {
            printf("%d\n", *value1 * *value2);
            break;
        }
    }

    shmdt(value1);
    shmctl(m1, IPC_RMID, 0);
    shmdt(value2);
    shmctl(m2, IPC_RMID, 0);
    return 0;
}
