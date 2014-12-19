#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
typedef struct nd
{
    int val;
    struct nd * left, *right;
} node;

///using node* as parameters also allows to parse only the subtrees if needed
node* insertNode(node* root,int n);
void preorder(node * root);///Simply lists the elemnts in preorder
void prettyPrint(node * root);///Ceeates that tree-like thing
void findNode(node * root,int n);
int findAllNodesThatAreOfDepthDepth(node * root, int * intArray, int depth,int *numberOfElements);///returns the number of nodes found
void deleteNode(node* root,int n);

int findMaxDepth(node * root,int * depth);///if you wand rootdepth to be 0, make the variable -1 on first call


#endif // FUNCTIONS_H_INCLUDED
