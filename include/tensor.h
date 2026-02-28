#ifndef TENSOR_H
#define TENSOR_H

#include "matrix_list.h"

int** tensor_product(Node* list, int* out_size);
void free_matrix(int** matrix, int size);
void out_file(FILE* fptr, int** matrix, int size);

#endif