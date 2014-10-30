#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char key;
    struct node *left;
    struct node *right;
}
NodeT;

NodeT *root;

NodeT* createbintree (FILE *fp)
{
    NodeT *tempvar;
    tempvar= (NodeT*) malloc (sizeof(NodeT));
    char test;
    if (fp != NULL)
    {
        test=fgetchar();
    }
    if (test=='#')
    {
        return NULL;
    }
    else
    {
        tempvar->key=test;
        tempvar->left=createbintree(fp);
        tempvar->right=createbintree(fp);
        return tempvar;
    }
    fclose(fp);
}

void postorder(NodeT *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->key);
    }

}

int main()
{
    printf("characters in your file:\n");
    FILE *fp;
    fp=fopen("D:/DSAprob4.6.2/file.doc","r");
    if (fp == NULL)
    {
        printf("err");
        exit(1);
    }
    root=createbintree(fp);

    postorder(root);
    return 0;
}
