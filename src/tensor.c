#include "tensor.h"
#include <stdlib.h>

int** tensor_product(Node* matrix_list, int* out_size)
{
    Node* aux = matrix_list;

    while (aux->next != NULL)
    {
        int result_size = aux->size * aux->next->size;
        int **result_matrix = (int**)malloc(result_size * sizeof(int*));
        for (int i = 0; i < result_size; i++)
        {
            result_matrix[i] = (int*)malloc(result_size * sizeof(int));
        }

        for (int i = 0; i < aux->size; i++)
        {
            for (int j = 0; j < aux->size; j++)
            {
                for (int k = 0; k < aux->next->size; k++)
                {
                    for (int l = 0; l < aux->next->size; l++)
                    {
                        result_matrix[i * aux->next->size + k][j * aux->next->size + l] = aux->matrix[i][j] * aux->next->matrix[k][l];
                    }
                }
            }
        }

        aux->next->matrix = result_matrix;
        aux->next->size = result_size;
        aux = aux->next;
    }

    *out_size = aux->size;
    return aux->matrix;
}