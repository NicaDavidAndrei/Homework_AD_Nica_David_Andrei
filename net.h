#ifndef NET_H
#define NET_H

// Definiton of a structure for a lobster that we will use in the program that inclues its id, weight and value
struct lobsters{
    int id;
    int size;
    int value;
};

// Definition of a structure for a matrix with the number of rows, number of columns, and a pointer to the matrix data.
struct a_matrix{
    int no_rows;
    int no_cols;
    int *matrix;
};

// Function prototypes


void generate_lobsters(struct lobsters *lobsters, int no_lobsters);
void print_lobsters(struct lobsters *lobsters, int no_lobsters);
void set_matrix_value(struct a_matrix matrix, int row_index, int column_index, int element_value);
void dynamic_programming_net_discrete(struct lobsters *lobsters, int no_lobsters, int net_capacity);
int get_matrix_value(struct a_matrix matrix, int row_index, int column_index);
int get_max(int val1, int val2);

#endif