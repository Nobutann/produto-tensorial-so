#include <stdlib.h>
#include "matrix_list.h"

static Node* create_node(int count, int data[count][count])
{
    Node* new = (Node*)malloc(sizeof(Node));
    new->matrix = (int**)malloc(count * sizeof(int*));
    for (int i = 0; i < count; i++)
    {
        new->matrix[i] = (int*)malloc(count * sizeof(int));
    }
    
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            new->matrix[i][j] = data[i][j];
        }
    }

    new->next = NULL;

    return new;
}

void insert_end(Node** head, int count, int data[count][count])
{
    Node* new = create_node(count, data);

    if (*head == NULL)
    {
        *head = new;
        return;
    }

    Node* aux = *head;

    while (aux->next != NULL)
    {
        aux = aux->next;
    }

    aux->next = new;
}