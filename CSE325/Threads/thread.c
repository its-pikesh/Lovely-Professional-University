#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pthread.h>


int sum = 0;

void * thread_func(void * arg) {
    int n = atoi(arg); // Convert string argument to integer.

    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    pthread_exit("Thread finished!");
}


int main() {
    pthread_t a_thread; // Thread declaration.
    char * arg = "5";
    void * result;

    pthread_create(&a_thread, NULL, thread_func, (void *)arg);
    pthread_join(a_thread, &result);

    printf("Thread finished and returned: %s" \
                   "\nSum is: %d\n", result, sum);

    exit(EXIT_SUCCESS);
}