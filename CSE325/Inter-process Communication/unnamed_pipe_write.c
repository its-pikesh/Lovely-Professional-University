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

    sprintf(buff, "hello");

    rd = popen("wc -c", "w"); // `wc -c` reads the number of characters. \
                                 `w` indicates that the file is opened in write mode.
    fwrite(buff, sizeof(char), strlen(buff), rd);

    pclose(rd);
    exit(EXIT_SUCCESS);
}