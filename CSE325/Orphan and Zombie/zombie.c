//
// Created by Faisal Alam on 24-03-2018.
//

/**
 * Creation of Zombie Process.
 *
 * A zombie process is that process which has completed execution via the exit system call, but still has an entry in the process table.
 * So, we create two child processes and makes the parent sleep for 30 seconds (and not wait for the child).
 * Thus the child process becomes a zombie process.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>


int main() {
    pid_t p;
    int i;

    for (i = 0; i < 2; ++i) {
        p = fork();

        if (p == 0)
        {
            printf("Child process having PID %d.\n", getpid());
            exit(EXIT_SUCCESS); // Let the child process exit immediately.
        }
        else if (p > 0)
        {
            printf("Parent process having PID: %d.\n", getpid());
        }
        else
        {
            perror("Fork failed!\n");
            exit(EXIT_FAILURE);
        }
    }

    // Let the parent process sleep for 30 seconds and then exit.
    sleep(30);
    exit(EXIT_SUCCESS);
}