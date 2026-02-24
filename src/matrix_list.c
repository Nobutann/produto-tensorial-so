#include <stdlib.h>
#include "matrix_list.h"

static Node* create_node(int data[2][2])
{
    Node* new = (Node*)malloc(sizeof(Node));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            new->matrix[i][j] = data[i][j];
        }
    }

    new->next = NULL;

    return new;
}

void insert_end(Node** head, int data[2][2])
{
    Node* new = create_node(data);

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