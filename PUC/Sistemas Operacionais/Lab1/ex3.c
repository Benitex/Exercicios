#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdio.h> 
#include <stdlib.h>

#define VECTOR_SIZE 10

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main(void) {
    int *x = (int *) malloc(sizeof(int) * VECTOR_SIZE);

    printf("Type 10 integers:\n");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        scanf("%d", &x[i]);
    }

    printf("\nInitial values:\n");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    int child = fork();

    if (child != 0) {
        waitpid(-1, NULL, 0);

        printf("Parent values:\n");
        for (int i = 0; i < VECTOR_SIZE; i++) {
            printf("%d ", x[i]);
        }
        printf("\n");
    } else {
        qsort(x, VECTOR_SIZE, sizeof(int), compare);
    }

    free(x);
    exit(0);

    return 0;
}
