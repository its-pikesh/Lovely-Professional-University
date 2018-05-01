#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>


int main() {
    int fd, n; char buff[100];
    fd = open("file", O_RDONLY);

    // Read 5 bytes from the beginning.
    n = read(fd, buff, 5);
    write(1, buff, n);
    printf("\n");
    fflush(stdout);

    // Pointer is now positioned 4 bytes from the beginning of the file.
    n = read(fd, buff, 4); // Read next 5 bytes from the file.
    write(1, buff, n);
    printf("\n");
    fflush(stdout);

    // Move the pointer to the beginning of the file.
    lseek(fd, 0, SEEK_SET);

    // Move pointer 5 bytes from its current location
    // and read 4 bytes from there.
    lseek(fd, 5, SEEK_CUR);
    n = read(fd, buff, 4);
    write(1, buff, n);
    printf("\n");
    fflush(stdout);

    // Move pointer 9 bytes before the end of the file
    // and read 8 bytes from this position.
    lseek(fd, -9, SEEK_END);
    n = read(fd, buff, 8);
    write(1, buff, n);
    printf("\n");
    fflush(stdout);

    close(fd);
    exit(EXIT_SUCCESS);
}
