#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


int main() {
    int res, n;
    char buff[100];

    res = open("fifo1", O_RDONLY);
    if (res == -1) {
        perror("Pipe does not exist.\n");
        exit(EXIT_FAILURE);
    }

    n = read(res, buff, sizeof(buff));

    printf("Data read: %s\n", buff);
    printf("\nTotal bytes read: %d\n", n);

    printf("Process %d terminated.\n", getpid());
    exit(EXIT_SUCCESS);
}