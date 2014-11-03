#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeT
{
    char *content;
    struct NodeT *left;
    struct NodeT *right ;
}NodeT;

/** The structure of a list for expression evaluation **/
typedef struct LisT
{
    char *content;
    struct LisT *next;
}LisT;

LisT *first, *last;

/** Useful function made to avoid to much writing **/
int IsOperation(char *c)
{
    return ((strcmp(c,"+")==0) || (strcmp(c,"-")==0) || (strcmp(c,"*")==0) || (strcmp(c,"/")==0));
}

/** Returns the first element in the list **/
LisT* GetFirst()
{
    return first;
}

/** Introduces an element at the end of the list **/
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

/** Removes the first element in the list **/
void RemoveFirst()
{
    if(first!=NULL)
    {
        first=first->next;
    }
}

/** Creates a tree from a list **/
NodeT *CreateTreeFromList()
{
    NodeT *node=(NodeT*)malloc(sizeof(NodeT));

    /** Get the first element of the list
        (we advance in the list by removing the first element) **/
    LisT *NextElement = GetFirst();
    node->content=NextElement->content;

    /** Remove the element from the list**/
    RemoveFirst();

    /** All the leaves must be operands **/
    if(!IsOperation(NextElement->content))
    {
        /** The operand is a leaf with NULL children **/
        node->left=NULL;
        node->right=NULL;
        return node;
    }
    else
    {
        /** The element is an operator.
            Each operator is the root of a subtree **/
        node->right = CreateTreeFromList();
        node->left= CreateTreeFromList();
    }
    return node;
}

/** Constructs the list from the prefix expression **/
NodeT *CreateTreeFromPrefixExpression(char* PrefixExpression)
{
    /** 'space' = split element **/
    const char splitter[1]=" ";
    char *ExpressionElement;

    ExpressionElement=strtok(PrefixExpression,splitter);
    while(ExpressionElement!=NULL)
    {
        AddLast(ExpressionElement);
        ExpressionElement=strtok(NULL,splitter);
    }

    /** The list is created.
        Now we create the tree from it. **/
    return CreateTreeFromList();
}
/** The traversals as in laboratory **/
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
    /** For postfix expression:
    strrev(PrefixExpression);
    NodeT * root = createTreeFromPrefixExpression(PrefixExpression);
    printf("\nPreorder:\n");
    preorder(root,0);
    printf("\nInorder:\n");
    inorder(root,0);
    printf("\nPostorder:\n");
    postorder(root,0);
    **/
    return 0;
}
