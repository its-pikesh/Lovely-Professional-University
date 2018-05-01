#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    pid_t p = fork();

    if (p < 0) {
        perror("Fork failed!\n");
        exit(EXIT_FAILURE);
    } else if (p == 0) {
        // Child process.

        for (int i = 1; i <= 10; ++i) {
            printf("%d ", i);
            fflush(stdout);
            sleep(1);
        }
    } else {
        // Parent process.

        for(int i = 11; i <= 20; ++i) {
            printf("%d ", i);
            fflush(stdout);
            sleep(1);
        }
    }
    
    exit(EXIT_SUCCESS);
}