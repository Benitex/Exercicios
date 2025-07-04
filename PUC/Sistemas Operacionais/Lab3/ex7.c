#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void sigcontHandler();

int main(void) {
    char *argv[] = {NULL};

    pid_t child1 = fork();
    if (child1 < 0) exit(-1);

    if (child1 == 0) {
        execv("./io1", argv);
    }
    kill(child1, SIGSTOP);

    pid_t child2 = fork();
    if (child2 < 0) exit(-1);

    if (child2 == 0) {
        execv("./io2", argv);
    }
    kill(child2, SIGSTOP);

    pid_t child3 = fork();
    if (child3 < 0) exit(-1);

    if (child3 == 0) {
        execv("./io3", argv);
    }
    kill(child3, SIGSTOP);

    int childTurn = 1;
    for (;;) {
        if (childTurn == 1) {
            kill(child1, SIGCONT);
            kill(child2, SIGSTOP);
            kill(child3, SIGSTOP);
            childTurn = 2;
            sleep(1);
        } else if (childTurn == 2) {
            kill(child1, SIGSTOP);
            kill(child2, SIGCONT);
            kill(child3, SIGSTOP);
            childTurn = 3;
            sleep(2);
        } else if (childTurn == 3) {
            kill(child1, SIGSTOP);
            kill(child2, SIGSTOP);
            kill(child3, SIGCONT);
            childTurn = 1;
            sleep(2);
        }
    }

    return 0;
}
