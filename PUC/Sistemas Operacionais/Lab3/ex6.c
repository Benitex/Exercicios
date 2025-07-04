#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void exitHandler();

int totalTime = 0;

int main(void) {
    signal(SIGUSR1, exitHandler);
    signal(SIGUSR2, exitHandler);

    while (1 < 2) {
        sleep(1);
        totalTime++;
    }

    return 0;
}

void exitHandler() {
    // If the call lasts less than a minute,
    // every second costs double the price
    if (totalTime < 60) {
        totalTime *= 2;
    }

    int minutes = totalTime / 60;
    int seconds = totalTime % 60;
    printf("Price: R$%d,%02d\n", minutes, seconds);

    exit(0);
}
