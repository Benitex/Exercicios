#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <sys/wait.h> 

int main(void) {
    int channel[2];
    pipe(channel);

    if (fork() == 0) {
        close(channel[0]);

        int *number = malloc(sizeof(int));
        *number = 0;

        while (*number < 10) {
            write(channel[1], number, sizeof(int));
            printf("Wrote number: %d\n", *number);
            sleep(1);
            *number += 1;
        }

        close(channel[1]);
        free(number);
        exit(0);
    }

    if (fork() == 0) {
        close(channel[1]);
        int *number = malloc(sizeof(int));;

        while (*number < 8) {
            read(channel[0], number, sizeof(int));
            printf("Read number in 1: %d\n", *number);
            sleep(2);
        }

        close(channel[0]);
        free(number);
        exit(0);
    }

    if (fork() == 0) {
        close(channel[1]);
        int *number = malloc(sizeof(int));;

        while (*number < 8) {
            read(channel[0], number, sizeof(int));
            printf("Read number in 2: %d\n", *number);
            sleep(2);
        }

        close(channel[0]);
        free(number);
        exit(0);
    }

    wait(NULL);

    close(channel[0]);
    close(channel[1]);
    return 0;
}
