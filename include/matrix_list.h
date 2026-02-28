#ifndef MATRIX_LIST_H
#define MATRIX_LIST_H

typedef struct Node
{
    int size;
    int** matrix;
    struct Node* next;
} Node;

void insert_end(Node** head, int count, int** data);

#endif