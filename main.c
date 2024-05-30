#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "net.h"

int main()
{
    clock_t start, end; // Variables to store the start and end times for CPU usage calculation

    struct lobsters *lobsters; // Pointer to a struct of lobsters (used for storing the details of each lobster)
    int no_lobsters, net_capacity; // Variables for the number of lobsters and the net capacity

    // Input for the net's capacity
    printf("Size of the net: ");
    scanf("%d", &net_capacity);

    printf("\n\n");

    // Input for the number of lobsters
    printf("Number of lobsters: ");
    scanf("%d", &no_lobsters);

    printf("\n\n");

    // Memory allocation for the lobsters. We use the "sizeof" operator in order to get the size of the data type.
    lobsters = malloc(no_lobsters * sizeof(struct lobsters)); 
    generate_lobsters(lobsters, no_lobsters); // Generation of lobsters with random sizes and values

    // We output the lobsters caught by assigning an id for each lobster, alongside their respective weight and value
    printf("\n=== Lobsters ===");
    print_lobsters(lobsters, no_lobsters);

    // Start timing the dynamic programming algorithm
    start = clock();
    dynamic_programming_net_discrete(lobsters, no_lobsters, net_capacity); // We apply the dynamic programming algorithm to determine the maximum value that can be obtained from the lobsters that can also fit in the net.
    end = clock();

    // Calculate and print the CPU time used
    double cpu_time_used = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nCPU time used: %f seconds\n", cpu_time_used);

    printf("\n\n");

    return 0;
}
