#include <stdio.h>
#include <stdlib.h>


//tree declaration
typedef struct node
{
    int key;
    struct node *left, *right;
} nodeT;

nodeT* insertNode(nodeT* node, int key);
void inorder(nodeT *root);
nodeT* searchNode(nodeT* root, int key);
nodeT* deleteNode(nodeT* root, int key);
