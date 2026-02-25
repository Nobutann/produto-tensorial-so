#include <stdio.h>
#include "matrix_list.h"
#include <stdlib.h>

int main(int argc, char* argv[])
{
    Node* matrix_list = NULL;

    for (int i = 0; i < argc; i++)
    {   
        FILE* fptr = fopen(argv[i+1], "r");

        int row = 2;
        int **matrix = (int**)malloc(row * sizeof(int*));
        for (int c = 0; c < row; c++)
        {
            matrix[c] = (int*)malloc(row * sizeof(int));
        }

        int* arr = (int*)malloc((row * row) * sizeof(int));
        int count = 0;
        
        while(fscanf(fptr, "%d", &arr[count]) == 1)
        {
            count++;
            if (count > row)
            {
                arr = (int*)realloc(arr, row + (1 * sizeof(int)));
                row++;
            }
        }

        free(arr);

        for (int j = 0; j < count; j++)
        {
            for (int k = 0; k < count; k++)
            {
                fscanf(fptr, "%d", &matrix[j][k]);
            }
        }

        fclose(fptr);
    
        insert_end(&matrix_list, count, matrix);

        for (int j = 0; j < row; j++)
        {
            free(matrix[j]);
        }
        free(matrix);        
    }

    return 0;
}