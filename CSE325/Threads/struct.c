#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>


typedef struct arguments {
    int arg1;
    int arg2;
} args;


void * thread_func(void * arguments) {
    args * arg = arguments;
    printf("Inside thread.\n");
    printf("First argument: %d\n" \
                   "Second argument: %d\n", arg->arg1, arg->arg2);

    pthread_exit(NULL);
}


int main() {
    pthread_t a_thread; // Thread declaration.
    args arg;
    arg.arg1 = 1;
    arg.arg2 = 2;

    pthread_create(&a_thread, NULL, thread_func, &arg);
    pthread_join(a_thread, NULL);
    printf("Thread finished.\n");

    exit(EXIT_SUCCESS);
}