#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int main() {
    int p, r;

    printf("Enter the number of processes: ");
    scanf("%d", &p);

    printf("Enter the number of resources: ");
    scanf("%d", &r);

    assert(r <= 100);

    int allocation[p][100]; // Number of allocated resources.
    int max[p][100]; // Number of maximum resources required.
    int need[p][100]; // Maximum allocation.
    int flag[p]; // To keep track of processes.

    int available[r]; // Number of instances of the available resources.
    int sequence[p+1000], c = 0; // To store the result.
    int state = 1; // 0 -> System is in unsafe state. \
                      1 -> System is in safe state.
    int count = 0;
    int i, j, k; // Loop variables.

    // Initially, no processes has been finished. \
    Hence, set them all to zero.
    memset(flag, 0, p * sizeof(int));

    printf("\n");
    for (i = 0; i < r; ++i) {
        printf("Enter number of instances of resource %d: ", i);
        scanf("%d", &available[i]);
    }

    for (i = 0; i < p; ++i) {
        for (j = 0; j < r; ++j) {
            printf("\nEnter current allocation for process p[%d] of resource %d: ", i, j);
            scanf("%d", &allocation[i][j]);
            printf("Enter maximum requirement of process p[%d] of resource %d: ", i, j);
            scanf("%d", &max[i][j]);

            need[i][j] = max[i][j] - allocation[i][j];
            printf("Need for process p[%d] of resource %d is: %d.\n", i, j, need[i][j]);
            fflush(stdout);
        }
    }
    printf("\n");

    for (i = 0; i < p; ++i) { // Loop for process.
        for (j = 0; j < p; ++j) { // Loop for process.
            count = 0;

            for (k = 0; k < r; ++k) { // Loop for resource.
                if (flag[j] == 0 && need[j][k] <= available[k]) {
                    available[k] += allocation[j][k];
                    allocation[j][k] = 0;
                    count++;

                    if (count == r) {
                        flag[j] = 1;
                        printf("Process %d has been allocated its required resource.\n", j);

                        sequence[c++] = j;
                    }
                    // If need for the current resource is satisfied, \
                    then we check for the next resource.
                    continue;
                }
                // Else if any one of the resources cannot be satisfied, \
                break the loop and check the next process.
                break;
            }
        }
    }
    printf("\n");

    for (i = 0; i < p; ++i) {
        if (flag[i] == 0) {
            state = 0;
            break;
        }
    }

    if (state == 0) {
        printf("\nSystem is in unsafe state.\n");
    } else {
        printf("\nSystem is in safe state.\n");
        printf("Safe sequence is: ");
        for (i = 0; i < c; ++i) {
            printf("%d ", sequence[i]);
        }
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}