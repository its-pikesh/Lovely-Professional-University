#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>


int main() {
    void * shared_mem;
    char buff[100];
    int shmId, n;

    shmId = shmget((key_t)1302, 1000, 0666|IPC_CREAT);
    printf("Key of shared memory is: %d\n", shmId);

    shared_mem = shmat(shmId, NULL, 0);
    printf("Process attached at %x\n", (int *) shared_mem);

    printf("Enter data to write to shared memory: ");
    fflush(stdout);
    read(0, buff, sizeof(buff));

    strcpy(shared_mem, buff);
    printf("Data written to shared memory: %s", shared_mem);

    exit(EXIT_SUCCESS);
}