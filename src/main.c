#include <stdio.h>
#include "matrix_list.h"

int main(int argc, char* argv[])
{
    Node* matrix_list = NULL;

    for (int i = 0; i < argc; i++)
    {   
        FILE* fptr = fopen(argv[i+1], "r");
        int matrix[2][2];

        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                fscanf(fptr, "%d", &matrix[j][k]);
            }
        }

        fclose(fptr);
    
        insert_end(&matrix_list, matrix);
    }

    return 0;
}