#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <semaphore.h>


int shared = 1;
sem_t s;

void * func1();
void * func2();


int main() {
    // int sem_init(sem_t *sem, int pshared, unsigned int value); \
    2nd argument is the number of process sharing this semaphore.
    sem_init(&s, 0, 1);

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

    sem_wait(&s);

    x = shared;
    x++;

    sleep(1);

    shared = x;

    sem_post(&s);
    pthread_exit(NULL);
}


void * func2() {
    int y;

    sem_wait(&s);

    y = shared;
    y--;

    sleep(1);

    shared = y;

    sem_post(&s);
    pthread_exit(NULL);
}