#ifndef MATRIX_LIST_H
#define MATRIX_LIST_H

typedef struct Node
{
    int matrix[2][2];
    struct Node* next;
} Node;

void insert_end(Node** head, int data[2][2]);

#endif