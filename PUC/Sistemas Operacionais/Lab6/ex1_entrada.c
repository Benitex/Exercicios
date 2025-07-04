#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO_NAME "ex1FIFO"

int main(void) {
    if (access(FIFO_NAME, F_OK) != 0) {
        if (mkfifo(FIFO_NAME, S_IRUSR | S_IWUSR) != 0) {
            printf("Error when creating fifo.\n");
        }
    } else {
        printf("FIFO accessed with success.\n");
    }

    int fifo = open(FIFO_NAME, O_WRONLY);
    if (fifo < 0) perror("Error when opening fifo for writing.\n");

    int data;
    while (1 < 2) {
        scanf("%d", &data);
        write(fifo, &data, sizeof(int));
    }

    close(fifo);
    return 0;
}
