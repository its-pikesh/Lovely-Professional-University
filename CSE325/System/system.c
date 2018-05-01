#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    printf("Before system.\n");
    // Run another process within the process and then wait for it to finish.
    system("ps");
    printf("After system.\n");

    exit(EXIT_SUCCESS);
}