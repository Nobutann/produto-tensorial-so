#ifndef MATRIX_LIST_H
#define MATRIX_LIST_H

typedef struct Node
{
    int** matrix;
    struct Node* next;
} Node;

void insert_end(Node** head, int count, int data[count][count]);

#endif