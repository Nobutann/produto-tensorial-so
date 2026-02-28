#include <stdio.h>
#include <stdlib.h>
#include "tensor.h"

int** tensor_product(Node* list, int* out_size)
{
    if (list == NULL)
    {
        *out_size = 0;
        return NULL;
    }

    int current_size = list->size;
    int** current = (int**)malloc(current_size * sizeof(int*));
    for (int i = 0; i < current_size; i++)
    {
        current[i] = (int*)malloc(current_size * sizeof(int));
        for (int j = 0; j < current_size; j++)
        {
            current[i][j] = list->matrix[i][j];
        }
    }

    Node* node = list->next;

    while (node != NULL)
    {
        int result_size = current_size * node->size;
        int** result = (int**)malloc(result_size * sizeof(int*));
        for (int i = 0; i < result_size; i++)
        {
            result[i] = (int*)malloc(result_size * sizeof(int));
        }

        for (int i = 0; i < current_size; i++)
        {
            for (int j = 0; j < current_size; j++)
            {
                for (int k = 0; k < node->size; k++)
                {
                    for (int l = 0; l < node->size; l++)
                    {
                        result[i * node->size + k][j * node->size + l] = current[i][j] * node->matrix[k][l];
                    }
                }
            }
        }

        free_matrix(current, current_size);
        current = result;
        current_size = result_size;
        node = node->next;
    }

    *out_size = current_size;
    
    return current;
}

void free_matrix(int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void out_file(FILE* fptr, int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            fprintf(fptr, "%d ", matrix[i][j]);
        }

        fprintf(fptr, "\n");
    }
}