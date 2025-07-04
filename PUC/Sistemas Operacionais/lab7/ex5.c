#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <sys/mman.h>

int main(int argc, char *argv[]) {
    struct stat sb;
    char *p;
    int fd;

    char *newString = "This is a new string to be added.";
    int newStringLength = strlen(newString);

    if (argc < 2) {
        fprintf (stderr, "usage: %s <file>\n", argv[0]);
        exit(1);
    }
    fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror ("open");
        exit(1);
    }
    if (fstat(fd, &sb)== -1) {
        perror ("fstat");
        exit(1);
    }
    if (!S_ISREG (sb.st_mode)) {
        fprintf (stderr, "%s is not a file\n", argv[1]);
        exit(1);
    }

    if (ftruncate(fd, sb.st_size + newStringLength) == -1) {
        perror("ftruncate");
        exit(1);
    }

    p = mmap(0, sb.st_size + newStringLength, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) {
        perror ("mmap");
        exit(1);
    }
    
    strcpy(p + sb.st_size, newString);

    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }

    if (munmap(p, sb.st_size + newStringLength) == -1) {
        perror("munmap");
        exit(1);
    }
    return 0;
}
