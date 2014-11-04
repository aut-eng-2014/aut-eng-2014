#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct nd
{
    int val;
    struct nd * left, *right;
} node;///5.4.4

node* insertNode(node* root,int n);
void preorder(node * root);
void findNode(node * root,int n);
void deleteNode(node* root,int n);

#endif // FUNCTIONS_H_INCLUDED
