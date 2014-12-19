#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
    char ch;
    struct node *left, *right;
} NodT;

NodT *root=  NULL;

NodT *construct()
{
    NodT *p;

    char c;
    printf("\nIntrodu numele nodului:\n ");
    c=getche();

    if(c=='#')
        return NULL;
    else
    {
        p=(NodT *)malloc(sizeof(NodT));
        p->ch=c;
        p->left=construct();
        p->right=construct();
    }
    return p;
}

void postorder(NodT *p,int level)
{
    int i;
    if(p!=NULL)
    {
        postorder(p->left,level+1);
        postorder(p->right,level+1);
        for(i=0; i<=level; i++)
            printf(" ");
        printf(" %c \n", p->ch);

    }
}

int main()
{

    root=construct();
    postorder(root,0);


    return 0;
}
