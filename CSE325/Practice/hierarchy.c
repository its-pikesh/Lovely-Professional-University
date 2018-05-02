#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


/**
 * Create the following hierarchy:
 *          P
 *         / \
 *        /   \
 *      C1     C2
 *     / \    /  \
 *   C11 C12 C21 C22
 */
int main() {
    pid_t p;
    p = fork;

    if (p > 0) {
        // Inside P
        p = fork();
        if (p == 0) {
            // Inside C2
            p = fork();
            if (p > 0) {
                // Inside C2
                p = fork();
                if (p == 0) {
                    // Inside C22
                    exit(0);
                }
            } else if (p == 0) {
                // Inside C21
                exit(0);
            }
            exit(0);
        }
    } else if (p == 0) {
        // Inside C1
        p = fork();
        if (p > 0) {
            // Inside C1
            p = fork();
            if (p == 0) {
                // Inside C12
                exit(0);
            }
        } else if (p == 0) {
            // Inside C11
            exit(0);
        }
        exit(0);
    }

    exit(0);
}