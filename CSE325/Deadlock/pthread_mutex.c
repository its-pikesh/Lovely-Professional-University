#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>


pthread_mutex_t first_mutex; // First mutex.
pthread_mutex_t second_mutex; // Second mutex.

void * func1();
void * func2();


int main() {
    // Initialize the locks to their default attributes.
    pthread_mutex_init(&first_mutex, NULL);
    pthread_mutex_init(&second_mutex, NULL);

    pthread_t one, two; // Declare thread variables.

    // Create two threads.
    pthread_create(&one, NULL, func1, NULL);
    pthread_create(&two, NULL, func2, NULL);

    // Join the threads.
    pthread_join(one, NULL);
    pthread_join(two, NULL);

    exit(EXIT_SUCCESS);
}


void * func1() {
    pthread_mutex_lock(&first_mutex);
    printf("Thread one acquired lock on '%s'.\n", "first_mutex");

    sleep(1);

    pthread_mutex_lock(&second_mutex);
    printf("Thread one acquired lock on '%s'.\n", "second_mutex");

    pthread_mutex_unlock(&second_mutex);
    printf("Thread one released lock from 'second_mutex'.\n");

    pthread_mutex_unlock(&first_mutex);
    printf("Thread one released lock from 'first_mutex'.\n");
}


void * func2() {
    pthread_mutex_lock(&second_mutex);
    printf("Thread one acquired lock on '%s'.\n", "second_mutex");

    sleep(1);

    pthread_mutex_lock(&first_mutex);
    printf("Thread one acquired lock on '%s'.\n", "first_mutex");

    pthread_mutex_unlock(&first_mutex);
    printf("Thread one released lock from 'first_mutex'.\n");

    pthread_mutex_unlock(&second_mutex);
    printf("Thread one released lock from 'second_mutex'.\n");
}