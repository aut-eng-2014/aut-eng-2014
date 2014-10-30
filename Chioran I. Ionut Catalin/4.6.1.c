#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char k;
    struct node *left;
    struct node *right;
}
NodeT;
NodeT *root;
NodeT* bintree (FILE *fp)
{
    NodeT *tVar ;
    tVar = (NodeT*) malloc (sizeof(NodeT));
    char check;
    if (fp != NULL)
    {
        check=fgetc(fp);
    }
    if (check=='#')
    {
        return NULL;
    }
    else
    {
        tVar ->k=check;
        tVar ->left=bintree(fp);
        tVar ->right=bintree(fp);
        return tVar ;
    }
    fclose(fp);
}

void porder(NodeT *root)
{
    if (root != NULL)
    {
        porder(root->left);
        porder(root->right);
        printf("\n%c", root->k);
    }

}
int main()
{
    printf("The chars in the file are:");
    FILE *fp;
    fp=fopen("C:\Users\lenovo\Desktop\faculta\txt.txt","r");//select the directory of extern file
    if (fp == NULL)
    {
        printf("Something was wrong!");
        exit(1);
    }
    root=bintree(fp);

    porder(root);
    return 0;
}
