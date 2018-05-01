#include <unistd.h>
#include <stdio.h>


int main() {
    printf("Before execl\n");
    execl("/bin/ps", "ps", "-a", NULL); // Replaces the process with a new process.
    printf("After execl\n"); // Hence, this line will not execute.
}