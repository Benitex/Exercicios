#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <sys/wait.h>

#define ROWS_AMOUNT 3
#define COLUMNS_AMOUNT 3
#define MATRIX_SIZE (ROWS_AMOUNT * COLUMNS_AMOUNT)

int main() {
    int sharedMemory = shmget(IPC_PRIVATE, sizeof(int) * MATRIX_SIZE, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    int *matrix1 = (int *) shmat(sharedMemory, 0, 0);
    for (int i = 0; i < MATRIX_SIZE; i++) {
        matrix1[i] = i + 1;
    }

    int sharedMemory2 = shmget(IPC_PRIVATE, sizeof(int) * MATRIX_SIZE, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    int *matrix2 = (int *) shmat(sharedMemory2, 0, 0);
    for (int i = 0; i < MATRIX_SIZE; i++) {
        matrix2[i] = 9 - i;
    }

    int sharedMemory3 = shmget(IPC_PRIVATE, sizeof(int) * MATRIX_SIZE, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    int *result = (int *) shmat(sharedMemory3, 0, 0);

    for (int row = 0; row < ROWS_AMOUNT; row++) {
        int childId = fork();
        if (childId < 0) exit(1);

        if (childId == 0) {
            for (int column = 0; column < COLUMNS_AMOUNT; column++) {
                int position = column + row * COLUMNS_AMOUNT;
                result[position] = matrix1[position] + matrix2[position];
            }
            exit(0);
        } else {
            waitpid(-1, NULL, 0);
        }
    }

    for (int i = 0; i < COLUMNS_AMOUNT; i++) {
        for (int i = 0; i < ROWS_AMOUNT; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }

    shmdt(matrix1);
    shmctl(sharedMemory, IPC_RMID, 0); 
    shmdt(matrix2);
    shmctl(sharedMemory2, IPC_RMID, 0); 

    return 0;
}
