#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>


int main() {
    int res = mkfifo("fifo1", 0777);
    printf("Named pipe created!\n");
    exit(EXIT_SUCCESS);
}