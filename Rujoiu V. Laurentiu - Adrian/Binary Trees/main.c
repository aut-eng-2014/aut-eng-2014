#include <stdio.h>
#include <stdlib.h>

typedef struct node /** typedef **/
{
    char value;
    struct node *left, *right;
} NodeT;

NodeT *root;

NodeT* createBinTree(FILE *f) /** Node creator **/
{

    NodeT *p;
    p = (NodeT*)malloc(sizeof(NodeT));
    char c;
    if (f != NULL)
    {
        fgetc(f);
    }
    if (c=='#')
    {
        return NULL;
    }
    else
    {
        p->value = c;
        p->left = createBinTree(f);
        p->right = createBinTree(f);
        return p;
    }
    fclose(f);
}

int Count(NodeT *root) /** shows the number of nodes **/
{
    if(root == NULL)
        return(0);
    else
        return(Count(root->left) + 1 + Count(root->right));
}

int Depth(NodeT *p) /** shows the depth of the tree **/
{
    int leftDepth;
    int rightDepth;
    if(p == 0)
        return(0);
    else
    {
        leftDepth = Depth(p->left);
        rightDepth = Depth(p->right);
    }
    if(leftDepth > rightDepth) return (leftDepth+1);
    else return rightDepth+1;
}

void Increasing(NodeT *p) /** puts the values in increasing order **/
{
    if(p == NULL)
        return;
    Increasing(p->left);
    printf("%c ", p->value);
    Increasing(p->right);
}

void preorder(NodeT *p) /** ROOT-LEFT-RIGHT traversal **/
{
    if(p != NULL)
    {
        printf("%c ", p->value);
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(NodeT *root) /** LEFT-ROOT-RIGHT traversal **/
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

void postorder(NodeT *root) /** LEFT-RIGHT-ROOT traversal **/
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->value);
    }
}



int main()
{
    FILE *f = fopen("dat.in", "r");

    if (f == NULL)
    {
        printf("error");
        exit(1);
    }
    root = createBinTree(f);

    postorder(root);
    printf("\n");
    printf("\nThe number of nodes is: %d", Count(root));
    printf("\nMax Depth is: %d", Depth(root));
    printf("\n");
    Increasing(root);

    return 0;
}
