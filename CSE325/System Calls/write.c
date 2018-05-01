#include <unistd.h>
#include <stdlib.h>


int main() {
    write(1, "Hello world!\n", 13);
    exit(EXIT_SUCCESS);
}