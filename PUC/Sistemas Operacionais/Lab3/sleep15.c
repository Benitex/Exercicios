#include <stdio.h>
#include <unistd.h>

int main (void) {
    fprintf(stdout, "indo dormir...\n");
    sleep(15);
    fprintf(stdout, "Acordei!\n");
    return 0;
}
