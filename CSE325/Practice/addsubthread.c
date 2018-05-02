#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


typedef struct arguments {
    int a;
    int b;
} args;


void * calc_sum(void *);
void * calc_diff(void *);

int sum, diff; // For storing the result.

int main() {
    args arg;

    printf("Enter the first number: ");
    scanf("%d", &arg.a);
    printf("Enter the second number: ");
    scanf("%d", &arg.b);

    pthread_t one, two; // Declare thread variables.

    // Create the threads.
    pthread_create(&one, NULL, calc_sum, &arg);
    pthread_create(&two, NULL, calc_diff, &arg);

    // Join the threads.
    pthread_join(one, NULL);
    pthread_join(two, NULL);

    printf("Result = %d\n", sum * diff);
    exit(EXIT_SUCCESS);
}


void * calc_sum(void * argument) {
    args *arg = argument;
    sum = arg->a + arg->b;
    pthread_exit(NULL);
}


void * calc_diff(void * argument) {
    args * arg = argument;
    diff = arg->a - arg->b;
    pthread_exit(NULL);
}