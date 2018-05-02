#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    FILE * rd;
    char buff[100];

    rd = popen("ls", "r");
    fread(buff, 1, sizeof(buff), rd);

    printf("%s\n", buff);

    pclose(rd);
    exit(EXIT_SUCCESS);
}