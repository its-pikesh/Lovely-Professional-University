#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


int main() {
    int res;
    char buff[] = "Hello world!";

    res = open("fifo1", O_WRONLY);
    if (res == -1) {
        perror("Pipe does not exist.\n");
        exit(EXIT_FAILURE);
    }

    write(res, buff, strlen(buff));
    printf("\nProcess %d terminated.\n", getpid());
    exit(EXIT_SUCCESS);
}