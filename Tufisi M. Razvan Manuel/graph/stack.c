#include <stdio.h>
#include <stdlib.h>
#include "Simplelinkedlist.h"

nodeT* newNode(int data)
{
    nodeT* stackNode =(nodeT*) malloc(sizeof(nodeT));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
void push(nodeT** root, int data)
{
    nodeT* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

int pop(nodeT** root)
{
    if (!root)
        return 0;
    nodeT* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(nodeT* root)
{
    if (!root)
        return 0;
    return root->data;
}

