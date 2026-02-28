#include <stdio.h>
#include "matrix_list.h"
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
    Node* matrix_list = NULL;

    for (int i = 1; i < argc; i++)
    {   
        FILE* fptr = fopen(argv[i], "r");

        int size = 2;
        int **matrix;

        int* arr = (int*)malloc((size * size) * sizeof(int));
        int count = 0;
        
        while(fscanf(fptr, "%d", &arr[count]) == 1)
        {
            count++;
            if (count >= (size * size))
            {
                size++;
                arr = (int*)realloc(arr, (size * size) * sizeof(int));
            }
        }

        free(arr);

        fclose(fptr);

        FILE* fptr2 = fopen(argv[i], "r");

        int mat_size = sqrt(count);

        matrix = (int**)malloc(mat_size * sizeof(int*));
        for (int j = 0; j < mat_size; j++)
        {
            matrix[j] = (int*)malloc(mat_size * sizeof(int));

        }
        for (int j = 0; j < mat_size; j++)
        {
            for (int k = 0; k < mat_size; k++)
            {
                fscanf(fptr2, "%d", &matrix[j][k]);
            }
        }

        fclose(fptr2);
    
        insert_end(&matrix_list, mat_size, matrix);

        for (int j = 0; j < mat_size; j++)
        {
            free(matrix[j]);
        }
        free(matrix);        
    }

    return 0;
}