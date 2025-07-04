#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define TEXT_MAXIMUM_LENGTH 2000

int main(void) {
    int file1 = open("file1.txt", O_RDONLY);
    dup2(file1, STDIN_FILENO);

    int file2 = open("file2.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    dup2(file2, STDOUT_FILENO);

    char fileContent[TEXT_MAXIMUM_LENGTH];
    read(STDIN_FILENO, fileContent, TEXT_MAXIMUM_LENGTH);
    write(STDOUT_FILENO, fileContent, strlen(fileContent) - 1);

    close(file1);
    close(file2);
    return 0;
}
