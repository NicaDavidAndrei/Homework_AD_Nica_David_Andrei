#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "net.h"

// Fucntion to generate lobsters with random sizes and values
void generate_lobsters(struct lobsters *lobsters, int no_lobsters)
{
    int iterator;
    time_t t;

    srand((unsigned) time(&t)); // Random number generator that uses time as a seed
    for (iterator = 0; iterator < no_lobsters; iterator++)
    {
        lobsters[iterator].id = iterator + 1; // Assignation of an id to each lobster
        lobsters[iterator].size = rand() % 100 + 1; // Assignation of a random size to each lobster
        lobsters[iterator].value = rand() % 100 + 1; //  Assignation of a random value to each lobster
    }
}

// Function to output the lobsters alongside their respective weight and value
void print_lobsters(struct lobsters *lobsters, int no_lobsters)
{
    int iterator;
    printf("\n Lobsters:");
    for (iterator = 0; iterator < no_lobsters; iterator++)
    {
     printf("\n id: %d weight: %d value:%d",lobsters[iterator].id,lobsters[iterator].size,lobsters[iterator].value); // Outputs the id, weight and value of each lobster
    }
}

// Function to set the value of a matrix element
void set_matrix_value(struct a_matrix matrix, int row_index, int column_index, int element_value)
{
    int position;
    position = row_index * matrix.no_cols + column_index;
    *(matrix.matrix + position) = element_value; // Value is set at the calculated position in the matrix
}

// Function to retrieve the value of a matrix element
int get_matrix_value(struct a_matrix matrix, int row_index, int column_index)
{
    int position;
    position = row_index * matrix.no_cols + column_index;
    return *(matrix.matrix + position); // Value is retrieved at the calculated position in the matrix
}

// Function that retrieves the maximum of two values
int get_max(int val1, int val2)
{
    if (val1 > val2)
    {
        return val1;
    }
    else
    {
        return val2;
    }
}

// Function that applies the dynamic programming algorithm to determine the maximum value that can be obtained from the lobsters and can also fit in (similar to the knapsack problem)
void dynamic_programming_net_discrete(struct lobsters *lobsters, int no_lobsters, int net_capacity)
{
    struct a_matrix matrix;
    int net_value;
    int lobsters_iterator;
    int weight_iterator;
    int value_current_size_without_current_lobster;
    int value_remaining_size_without_current_lobster;
    int value_current_size_plus_current_lobster;
    int value_max;
    int net_remaining_capacity;

    // Matrix initialization 
    matrix.no_rows = no_lobsters + 1;
    matrix.no_cols = net_capacity + 1;
    matrix.matrix = calloc((matrix.no_rows) * (matrix.no_cols), sizeof(int));

    for (lobsters_iterator = 0; lobsters_iterator <= no_lobsters; lobsters_iterator++)
    {
        for (weight_iterator = 0; weight_iterator <= net_capacity; weight_iterator++)
        {
            if (lobsters_iterator == 0 || weight_iterator == 0)
            {
                set_matrix_value(matrix, lobsters_iterator, weight_iterator, 0);
            }
            else
            {
                int lobster_weight = lobsters[lobsters_iterator - 1].size;
                int lobster_value = lobsters[lobsters_iterator - 1].value;

                value_current_size_without_current_lobster = get_matrix_value(matrix, lobsters_iterator - 1, weight_iterator);

                net_remaining_capacity = weight_iterator - lobster_weight;

                if (lobster_weight <= weight_iterator && net_remaining_capacity >= 0)
                {
                    value_current_size_plus_current_lobster = get_matrix_value(matrix, lobsters_iterator - 1, net_remaining_capacity) + lobster_value;
                    value_max = get_max(value_current_size_without_current_lobster, value_current_size_plus_current_lobster);
                    set_matrix_value(matrix, lobsters_iterator, weight_iterator, value_max);
                }
                else
                {
                    set_matrix_value(matrix, lobsters_iterator, weight_iterator, value_current_size_without_current_lobster);
                }
            }
        }
    }
    
    net_value = get_matrix_value(matrix, no_lobsters, net_capacity);
    free(matrix.matrix); // Freeing the memory allocated for the matrix

    // We output the biggest value that can be obtained from the lobsters and can also fit in the net
    printf("\n=== Value in the net %d ===", net_value);
    printf("\n");
}