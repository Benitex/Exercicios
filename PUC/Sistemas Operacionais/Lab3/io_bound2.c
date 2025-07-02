#include <stdio.h>
#include <unistd.h>

int main(void) {
    while (1) {
        printf("IO 2\n");
        usleep(500000); // Sleep for 0.5 seconds
    }
    return 0;
}
