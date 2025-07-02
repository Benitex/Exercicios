#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h>

#define TEXT_MAXIMUM_LENGTH 10

int main(void) {
    int channel[2];
    pipe(channel);

    if (fork() == 0) {
        char text[TEXT_MAXIMUM_LENGTH] = "test";

        close(channel[0]);
        write(channel[1], text, TEXT_MAXIMUM_LENGTH);

        printf("Sent text: %s\n", text);
        close(channel[1]);
    } else {
        char text[TEXT_MAXIMUM_LENGTH];

        close(channel[1]);
        read(channel[0], text, TEXT_MAXIMUM_LENGTH);

        printf("Received text: %s\n", text);
        close(channel[0]);
    }

    return 0;
}
