#include <stdio.h>
#include <unistd.h>

void *memorypool;

void *myallocate(int n) {
    return sbrk(n);
}

void initmemorypool(void) {
    memorypool = sbrk(0);
}

void resetmemorypool(void) {
    brk(memorypool);
}

int main(void) {
    initmemorypool();

    int *number = (int *) myallocate(sizeof(int));
    *number = 42;
    printf("Allocated number: %d\n", *number);
    resetmemorypool();

    return 0;
}
