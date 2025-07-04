#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <sys/mman.h>
#include <sys/time.h>

int main(int argc, char *argv[]) {
    struct stat sb;
    char *p;
    int fd;

    struct timeval start, end;

    if (argc < 2) {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        exit(1);
    }

    gettimeofday(&start, NULL);

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    if (fstat(fd, &sb)== -1) {
        perror("fstat");
        exit(1);
    }
    if (!S_ISREG (sb.st_mode)) {
        fprintf (stderr, "%s is not a file\n", argv[1]);
        exit(1);
    }

    p = mmap(0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }

    int pageSize = getpagesize();
    printf("Used %ld pages of size %d \n", sb.st_size / pageSize + 1, pageSize);

    gettimeofday(&end, NULL);
    printf("Read time with mmap: %ld microseconds\n", (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec));

    gettimeofday(&start, NULL);

    fd = open(argv[1], O_RDONLY);
    char *buffer = malloc(sb.st_size);
    read(fd, buffer, sb.st_size);

    gettimeofday(&end, NULL);

    printf("Read time with read: %ld microseconds\n", (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec));

    free(buffer);
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }

    // for (len = 0; len < sb.st_size; len++) putchar(p[len]);

    if (munmap(p, sb.st_size) == -1) {
        perror("munmap");
        exit(1);
    }
    return 0;
}
