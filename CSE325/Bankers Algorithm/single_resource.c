#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    int p; // Number of processes.

    printf("Enter the number of processes: ");
    scanf("%d", &p);

    int allocation[p]; // Number of allocated resources.
    int max[p]; // Number of maximum resources required.
    int need[p]; // Maximum allocation.
    int flag[p]; // To keep track of processes.

    int available; // Number of instances of the available resources.
    int sequence[p+1000], k = 0; // To store the result.
    int state = 1; // 0 -> System is in unsafe state. \
                  1 -> System is in safe state.

    int i, j; // Loop variables.


    // Initially, no processes has been finished. \
    Hence, set them all to zero.
    memset(flag, 0, p * sizeof(int));

    printf("Enter the number of instances of the resource: ");
    scanf("%d", &available);

    for (i = 0; i < p; ++i) {
        printf("\nEnter current allocation for process p[%d]: ", i);
        scanf("%d", &allocation[i]);
        printf("Enter maximum requirement of process p[%d]: ", i);
        scanf("%d", &max[i]);

        need[i] = max[i] - allocation[i];
        printf("Need for process p[%d] is: %d.\n", i, need[i]);
        fflush(stdout);
    }
    printf("\n"); // Just for beautification!

    for (i = 0; i < p; ++i) {
        for (j = 0; j < p; ++j) {
            if (flag[j] == 0 && need[j] <= available) {
                available += allocation[j];
                flag[j] = 1;
                printf("Process p[%d] has been allocated the resources.\n", j);
                sequence[k++] = j;
            }
        }
    }

    for (i = 0; i < p; ++i) {
        if (flag[i] == 0) {
            state = 0; // System in unsafe state.
            break;
        }
    }

    if (state == 0) {
        printf("\nSystem is in unsafe state.\n");
    } else {
        printf("\nSystem is in safe state.\n");
        printf("Safe sequence is: ");
        for (i = 0; i < k; ++i) {
            printf("%d ", sequence[i]);
        }
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}
