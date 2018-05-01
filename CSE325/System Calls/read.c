#include <unistd.h>
#include <stdlib.h>


int main() {
    ssize_t n; char buff[50];

    n = read(0, buff, 50);
    write(1, buff, n);

    exit(EXIT_SUCCESS);
}