#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdio.h> 
#include <stdlib.h>

int main(void) {
    int child = fork();

    printf("%d\n", child);
    if (child != 0) {
        waitpid(-1, NULL, 0);
    }

    return 0;
}
