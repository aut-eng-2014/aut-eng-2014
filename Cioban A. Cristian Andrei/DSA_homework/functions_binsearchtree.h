#include <stdlib.h>
#include <stdio.h>

typedef struct Tree {

	int data;
	struct Tree *left, *right;
}nodeT;

nodeT *FindMin(nodeT *node);
nodeT *FindMax(nodeT *node);
nodeT *Insert(nodeT *node, int data);
nodeT *Delete(nodeT *node, int data);
nodeT *Find(nodeT *node, int data);
//prints
void Preorder(nodeT *p, int level);
void Inorder(nodeT *p, int level);
void Postorder(nodeT *p, int level);
