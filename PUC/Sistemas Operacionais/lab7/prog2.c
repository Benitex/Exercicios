#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <sys/mman.h>

#define FILE_NAME "example.bin"

int main(void) {
    int *p;
    int fd;

    fd = open(FILE_NAME, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (ftruncate(fd, sizeof(int)) == -1) {
        perror("ftruncate");
        close(fd);
        exit(1);
    }

    p = mmap(0, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    printf("Received value: %d\n", *p);
    *p = 24;
    printf("Current value: %d\n", *p);

    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }

    if (munmap(p, sizeof(int)) == -1) {
        perror("munmap");
        exit(1);
    }
    return 0;
}
