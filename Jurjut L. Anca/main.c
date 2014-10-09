#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x;
    struct node *left, *right;
}nodeT;

nodeT *newnode(int x)
{
    nodeT *node = (nodeT *)malloc(sizeof(nodeT));
    node->x = x;
    node->left = node->right = NULL;
    return(node);
}

void inorder(nodeT *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\n    ",root->x);
        inorder(root->right);
    }
}

void PreviousPointer(nodeT *root)
{
    static struct node *pre = NULL;

    if (root != NULL)
    {
        PreviousPointer(root->left);
        root->left = pre;
        pre = root;
        PreviousPointer(root->right);
    }
}

nodeT *NextPointer(nodeT *root)
{
    nodeT *prev = NULL;
    while (root && root->right != NULL)
    {
        root = root->right;
    }
    while (root && root->left != NULL)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }
    return (root);
}

nodeT *BinTreeToDLL(nodeT *root)
{
    PreviousPointer(root);
    return NextPointer(root);
}

void show(nodeT *root)
{
    while (root != NULL)
    {
        printf("%d  ", root->x);
        root = root->right;
    }
}

int main(void)
{
    nodeT *root = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(3);
    root->left->left  = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);

    inorder(root);

    struct node *head = BinTreeToDLL(root);

    printf("\n DDL:");
    show(head);
    return 0;
}
