#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>


int main() {
    int fd, n; char buff[100], ans[100];

    printf("Enter data to write on the file: ");
    fflush(stdout);
    n = read(0, buff, 50);

    fd = open("file1", O_CREAT|O_WRONLY, 0777);
    write(fd, buff, n);
    close(fd);

    fd = open("file1", O_RDONLY);
    read(fd, ans, n);
    close(fd);
    write(1, ans, n);

    exit(EXIT_SUCCESS);
}