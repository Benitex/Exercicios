#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    int child = fork();

    if (child != 0) {
        waitpid(-1, NULL, 0);
    } else {
        char *argv[] = {"echo", "Test", NULL};
        execv("/bin/echo", argv);
    }

    return 0;
}
