#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>


int main() {
    int shmId;
    void * shared_mem;

    shmId = shmget((key_t)1302, 1000, 0666);
    printf("Key of shared memory is: %d\n", shmId);

    shared_mem = shmat(shmId, NULL, 0);
    printf("Process attached at %x\n", (int *) shared_mem);

    printf("Data read from shared memory: %s", shared_mem);

    exit(EXIT_SUCCESS);
}