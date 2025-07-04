#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define STRING_MAX_LENGTH 500
#define CLIENT_FIFO_NAME "clientFIFO"
#define SERVER_FIFO_NAME "serverFIFO"

int main(void) {
    if (access(SERVER_FIFO_NAME, F_OK) != 0) {
        if (mkfifo(SERVER_FIFO_NAME, S_IRUSR | S_IWUSR) != 0) {
            printf("Error when creating server fifo.\n");
        }
    }

    if (access(CLIENT_FIFO_NAME, F_OK) != 0) {
        if (mkfifo(CLIENT_FIFO_NAME, S_IRUSR | S_IWUSR) != 0) {
            printf("Error when creating client fifo.\n");
        }
    }

    int server_fifo = open(SERVER_FIFO_NAME, O_RDONLY);
    if (server_fifo < 0) {
        perror("Error when opening server fifo for writing.\n");
        exit(EXIT_FAILURE);
    }

    int client_fifo = open(CLIENT_FIFO_NAME, O_WRONLY);
    if (client_fifo < 0) {
        perror("Error when opening client fifo for reading.\n");
        close(server_fifo);
        exit(EXIT_FAILURE);
    }

    char string[STRING_MAX_LENGTH];
    while (1 < 2) {
        read(server_fifo, string, STRING_MAX_LENGTH);

        for (int i = 0; string[i] != '\0' && i < STRING_MAX_LENGTH; i++) {
            string[i] = toupper(string[i]);
        }

        write(client_fifo, string, STRING_MAX_LENGTH);
    }

    close(server_fifo);
    close(client_fifo);
    return 0;
}
