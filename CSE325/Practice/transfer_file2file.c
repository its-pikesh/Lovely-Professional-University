#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>

int main() {
    int fd1, fd2, n;
    char file1[100], file2[100], buff[100];

    printf("Enter the name of file to copy content from: ");
    scanf("%s", file1);

    fd1 = open(file1, O_RDONLY);
    if(fd1 == -1) {
        printf("Error opening file try again.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter the name of file to copy content to: ");
    scanf("%s", file2);

    fd2 = open(file2, O_CREAT|O_TRUNC|O_WRONLY, 0777);
    if(fd2 == -1) {
        printf("Error opening file try again.\n");
        exit(EXIT_FAILURE);
    }

    while ((n = read(fd1, buff, sizeof(buff))) != 0) {
        write(fd2, buff, n);
    }

    close(fd1);
    close(fd2);

    printf("Data successfully copied from %s to %s.\n",file1, file2);
    exit(EXIT_SUCCESS);
}
