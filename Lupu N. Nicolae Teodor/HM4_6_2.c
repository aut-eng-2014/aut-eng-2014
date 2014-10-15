#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeT
{
    char *content;
    struct NodeT *left;
    struct NodeT *right ;
}NodeT;


typedef struct LisT
{
    char *content;
    struct LisT *next;
}LisT;

LisT *first, *last;

int IsOperation(char *c)
{
    return ((strcmp(c,"+")==0) || (strcmp(c,"-")==0) || (strcmp(c,"*")==0) || (strcmp(c,"/")==0));
}


LisT* GetFirst()
{
    return first;
}

void AddLast(char *content)
{
    if(first==NULL)
    {
        first=(LisT*)malloc(sizeof(LisT));
        first->content=content;

    }
    else
        if(last==NULL)
        {
            last=(LisT*)malloc(sizeof(LisT));
            last->content=content;
            first->next=last;
            last->next=NULL;
        }
        else
        {
            LisT *node=(LisT*) malloc(sizeof(LisT));
            node->content=content;
            node->next=NULL;
            last->next=node;
            last=node;
        }
}

void RemoveFirst()
{
    if(first!=NULL)
    {
        first=first->next;
    }
}

NodeT *CreateTreeFromList()
{
    NodeT *node=(NodeT*)malloc(sizeof(NodeT));

    LisT *NextElement = GetFirst();
    node->content=NextElement->content;

    RemoveFirst();

    if(!IsOperation(NextElement->content))
    {
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    else
    {

        node->right = CreateTreeFromList();
        node->left= CreateTreeFromList();
    }
    return node;
}


NodeT *CreateTreeFromPrefixExpression(char* PrefixExpression)
{
    const char splitter[1]=" ";
    char *ExpressionElement;

    ExpressionElement=strtok(PrefixExpression,splitter);
    while(ExpressionElement!=NULL)
    {
        AddLast(ExpressionElement);
        ExpressionElement=strtok(NULL,splitter);
    }


    return CreateTreeFromList();
}

void preorder( NodeT *p, int level )
{
    int i;
    if (p!=NULL)
    {
        for (i=0;i<=level;i++)
            printf(" ");
        printf("%s\n", p->content);
        preorder(p->left, level+1);
        preorder(p->right, level+1);
    }
}

void inorder(NodeT *p, int level )
{
    int i;
    if (p!=NULL)
    {
        inorder(p->left, level+1);
        for (i=0;i<=level;i++)
            printf(" ");
        printf("%s\n", p->content);
        inorder(p->right, level+1);
    }
}

void postorder(NodeT *p, int level )
{
    int i;
    if (p!=NULL)
    {
        postorder(p->left , level+1);
        postorder(p->right, level+1);
        for (i=0;i<=level;i++)
            printf(" ");
        printf("%s\n", p->content);
    }
}


int main()
{
    char* PrefixExpression = (char*) malloc(sizeof(char)*400);
    gets(PrefixExpression);
    NodeT * root = CreateTreeFromPrefixExpression(PrefixExpression);
    printf("\nPreorder:\n");
    preorder(root,0);
    printf("\nInorder:\n");
    inorder(root,0);
    printf("\nPostorder:\n");
    postorder(root,0);

    return 0;
}
