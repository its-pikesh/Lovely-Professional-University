#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>


int shared = 1;
pthread_mutex_t l;

void * func1();
void * func2();


int main() {
    pthread_mutex_init(&l, NULL);

    pthread_t one, two;
    pthread_create(&one, NULL, func1, NULL);
    pthread_create(&two, NULL, func2, NULL);

    pthread_join(one, NULL);
    pthread_join(two, NULL);

    printf("The final value of the shared variable is: %d\n", shared);
    exit(EXIT_SUCCESS);
}


void * func1() {
    int x;

    pthread_mutex_lock(&l);

    x = shared;
    x++;

    sleep(1);

    shared = x;

    pthread_mutex_unlock(&l);
    pthread_exit(NULL);
}


void * func2() {
    int y;

    pthread_mutex_lock(&l);

    y = shared;
    y--;

    sleep(1);

    shared = y;

    pthread_mutex_unlock(&l);
    pthread_exit(NULL);
}