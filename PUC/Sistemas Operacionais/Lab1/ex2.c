#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdio.h> 
#include <stdlib.h>

int main(void) {
    int x = 1;
    printf("Initial value %d\n", x);

    int child = fork();

    if (child != 0) {
        waitpid(-1, NULL, 0);
        printf("Parent value %d\n", x);
    } else {
        x = 5;
        printf("Child value %d\n", x);
    }

    exit(0);

    return 0;
}
