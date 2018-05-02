#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>


int main() {
    pid_t p;
    int fd[2]; // Pipe

    pipe(fd);
    p = fork();

    if (p < 0) {
        perror("Fork failed!\n");
        exit(EXIT_FAILURE);
    } else if (p == 0) {
        // Inside the child process.

        sleep(1);

        close(fd[1]); // Close the write end.
        char message[100];

        printf("Child received: ");
        fflush(stdout);
        write(1, message, read(fd[0], message, sizeof(message)));
    } else {
        // Inside the parent process.

        close(fd[0]); // Close the read end.
        char message[] = "Hello, child!";
        write(fd[1], message, sizeof(message));

        wait(NULL); // Wait for the child to finish its execution.
        printf("\n");
    }

    exit(EXIT_SUCCESS);
}