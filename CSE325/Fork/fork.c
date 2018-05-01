#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Create the following hierarchy.
 *
 *      P
 *     / \
 *    /   \
 *   C1    C2
 */

int main() {
    pid_t p;
    p = fork();

    if (p == 0) {
        // Inside the child process.

        printf("Child process having ID: %d\n", getpid());
        printf("Parent of child %d is %d\n", getpid(), getppid());
    } else if (p > 0) {
        // Inside the parent process.

        p = fork();
        if (p == 0) {
            // Inside the second child process.

            printf("Child process having ID: %d\n", getpid());
            printf("Parent of child %d is %d\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        } else if (p < 0) {
            perror("Fork failed!\n");
            exit(EXIT_FAILURE);
        }

        wait(NULL);
        printf("Parent process having ID: %d\n", getpid());
    } else {
        perror("Fork failed!\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}