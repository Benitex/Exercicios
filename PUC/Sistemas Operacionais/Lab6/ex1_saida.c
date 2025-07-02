#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void) {
    int fifo = open("ex1FIFO", O_RDONLY);
    if (fifo < 0) perror("Error when opening fifo for reading.\n");

    int data;
    while (1 < 2) {
        read(fifo, &data, sizeof(int));
        printf("%d\n", data);
    }

    close(fifo);
    return 0;
}
