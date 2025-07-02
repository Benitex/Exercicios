#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void sigcontHandler();

int main(void) {
    int contextChanges = 10;

    signal(SIGCONT, sigcontHandler);

    pid_t child2;
    pid_t child1 = fork();
    if (child1 < 0) exit(-1);

    if (child1 == 0) {
        while (1 < 2) { }
    } else {
        child2 = fork();
        if (child2 < 0) exit(-1);

        if (child2 == 0) {
            while (1 < 2) { }
        } else {
            for (int i = 0; i < contextChanges; i++) {
                int childTurn = i % 2 + 1;
                kill(
                    childTurn == 1 ? child1 : child2,
                    SIGCONT
                );
                kill(
                  childTurn == 1 ? child2 : child1,
                  SIGSTOP
                );
                sleep(1);
            }

            kill(child1, SIGKILL);
            kill(child2, SIGKILL);
        }
    }

    return 0;
}

void sigcontHandler() {
    printf("Activating process %d\n", getpid());
}
