#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
    char ch;
    struct node *left, *right;
} NodT;

NodT *root;

NodT *construct(FILE *pf)
{
    NodT *p;

    char c;
    while( ( c = fgetc(pf) ) != EOF )
    {
        if(c=='#')
            return NULL;
        else
        {
            p=(NodT *)malloc(sizeof(NodT));
            p->ch=c;
            p->left=construct(pf);
            p->right=construct(pf);
        }
        return p;
    }
    fclose(pf);
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
        printf("\t %c \n", p->ch);

    }
}

int main()
{
    printf("output:\n");
    FILE *pf;
    pf=fopen("in.txt","r");

    root=construct(pf);
    postorder(root,0);


    return 0;
}
