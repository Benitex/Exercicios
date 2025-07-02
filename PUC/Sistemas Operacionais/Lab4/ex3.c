#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    int channel[2];
    pipe(channel);

    if (fork() == 0) {
        dup2(channel[1], STDOUT_FILENO);
        close(channel[0]);
        close(channel[1]);
        execlp("ps", "ps", NULL);
    }

    if (fork() == 0) {
        dup2(channel[0], STDIN_FILENO);
        close(channel[0]);
        close(channel[1]);
        execlp("wc", "wc", NULL);
    }

    close(channel[0]);
    close(channel[1]);

    return 0;
}
