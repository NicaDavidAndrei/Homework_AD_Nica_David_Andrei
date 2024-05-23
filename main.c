#include <stdio.h>
#include <stdlib.h>
#include "net.h"

int main()
{

    struct lobsters *lobsters; //pointer to a struct of lobsters (used for storing the details of each lobster)
    int no_lobsters, net_capacity; // variables for the number of lobsters and the net capacity

    // Input for the nets capacity
    printf("Size of the net: ");
    scanf("%d",&net_capacity);

    printf("\n\n");

    // Input for the number of lobsters
    printf("Number of lobsters: ");
    scanf("%d",&no_lobsters);

    printf("\n\n");

    lobsters = malloc(no_lobsters * sizeof(struct lobsters)); // Memory allocation for the lobsters. We use the "sizeof" operator in order to get the size of the data type.
    generate_lobsters(lobsters, no_lobsters); // Generation of lobstars with random sizes and values

    // We output the lobsters caught by assigning an id for each lobster, alongside their respective weight and value
    printf("\n=== Lobsters ===");
    print_lobsters(lobsters , no_lobsters);

    dynamic_programming_net_discrete(lobsters, no_lobsters, net_capacity); // We apply the dynamic program algorithm so that we can determine the maximum value that can be obtained from the lobsters and can also fit in the net.

    printf("\n\n");

    return 0;
  
}
