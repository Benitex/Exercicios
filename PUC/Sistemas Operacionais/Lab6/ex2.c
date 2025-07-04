#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define STRING_MAX_LENGTH 500
#define FIFO_NAME "ex2FIFO"

int main(void) {
    int fifo;

    if (access(FIFO_NAME, F_OK) != 0) {
        if (mkfifo(FIFO_NAME, S_IRUSR | S_IWUSR) != 0) {
            printf("Error when creating fifo.\n");
        }
    } else {
        printf("FIFO accessed with success.\n");
    }

    if (fork() == 0) {
        if (fork() == 0) {
            fifo = open(FIFO_NAME, O_WRONLY);
            if (fifo < 0) perror("Error when opening fifo for writing.\n");

            char string[STRING_MAX_LENGTH] = "teste2";
            write(fifo, string, sizeof(char) * STRING_MAX_LENGTH);
        } else {
            fifo = open(FIFO_NAME, O_WRONLY);
            if (fifo < 0) perror("Error when opening fifo for writing.\n");

            char string[STRING_MAX_LENGTH] = "teste1";
            write(fifo, string, sizeof(char) * STRING_MAX_LENGTH);
        }
        close(fifo);
        exit(0);
    } else {
        fifo = open(FIFO_NAME, O_RDONLY);
        if (fifo < 0) perror("Error when opening fifo for reading.\n");

        waitpid(-1, 0, 0);

        char *string = (char*) malloc(sizeof(char) * STRING_MAX_LENGTH);
        while (read(fifo, string, sizeof(char) * STRING_MAX_LENGTH) > 0) {
            printf("%s\n", string);
        }
        close(fifo);
        free(string);
    }

    return 0;
}
