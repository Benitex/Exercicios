#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(void) {
    signal(SIGKILL, SIG_IGN);
    raise(SIGKILL);
    return 0;
}
