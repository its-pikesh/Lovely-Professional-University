#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>


int shared = 1;

void * func1();
void * func2();


int main() {
    pthread_t one, two; // Declare two threads.

    // Create the threads.
    pthread_create(&one, NULL, func1, NULL);
    pthread_create(&two, NULL, func2, NULL);

    // Join the threads.
    pthread_join(one, NULL);
    pthread_join(two, NULL);

    printf("The final value of the shared variable is: %d\n", shared);
    exit(EXIT_SUCCESS);
}


void * func1() {
    int x;
    x = shared;
    x++;

    sleep(1);

    shared = x;

    pthread_exit(NULL);
}


void * func2() {
    int y;
    y = shared;
    y--;

    sleep(1);

    shared = y;

    pthread_exit(NULL);
}