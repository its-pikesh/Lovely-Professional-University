#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>


int main() {
    char buff[100], reader[10]; int n, fd1, fd2;
    printf("Enter data to be written on the first file: ");
    fflush(stdout);
    n = read(0, buff, 100);

    fd1 = open("file1", O_CREAT|O_TRUNC|O_WRONLY, 0777);
    write(fd1, buff, n);
    close(fd1);

    fd1 = open("file1", O_RDONLY, 0777);
    fd2 = open("file2", O_CREAT|O_TRUNC|O_WRONLY, 0777);

    while ((n = read(fd1, reader, sizeof(reader))) != 0) {
        write(fd2, reader, n);
    }

    close(fd1);
    close(fd2);

    printf("Data copied successfully!\n");
    exit(EXIT_SUCCESS);
}