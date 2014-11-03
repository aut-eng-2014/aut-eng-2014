
#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    struct tree *left;
    struct tree *right;
    char key;
}treeNode;

typedef struct stacks
{
    struct stacks *next;
    treeNode *element;
}stackS;


int isoperator(char x)
{
    switch (x)
    {
    case '+':
        {
            return 1;
            break;
        }
    case '-':
        {
            return 1;
            break;
        }
    case '*':
        {
            return 1;
            break;
        }
    case '/':
        {
            return 1;
            break;
        }
    default:
        {
            return 0;
            break;
        }
    }

}

stackS *insertelement(stackS *tp, char x)
{
    stackS *t=(stackS*)malloc(sizeof(stackS));
    treeNode *p=(treeNode*)malloc(sizeof(treeNode));
    p->key=x;
    p->left=NULL;
    p->right=NULL;
    t->element=p;
    t->next=tp;
    return t;
}

stackS *reforge(stackS *tp, char x)
{
    treeNode *t=(treeNode*)malloc(sizeof(treeNode));
    t->key=x;
    stackS *p,*o;
    stackS *newstelement=(stackS*)malloc(sizeof(stackS));
    o=tp;
    p=o->next;
    t->left=p->element;
    t->right=o->element;
    newstelement->element=t;
    newstelement->next=p->next;

    return newstelement;
}
void printreePreorder(treeNode *r)
{
    if(r!=NULL)
    {
        printf("%c ",r->key);
        printreePreorder(r->left);
        printreePreorder(r->right);
    }
}

void copy_bintree(treeNode *r, treeNode *n)
{
    if(r!=NULL)
    {
        treeNode *a=(treeNode*)malloc(sizeof(treeNode));
        a->key=r->key;
        a->left=r->left;
        a->right=r->right;
        copy_bintree(r->left,a->left);
        copy_bintree(r->right,a->right);
        n=a;
    }
}

treeNode *remake_prefix(treeNode *r)
{
    //left = next right= previous

    treeNode *actual=r;
    treeNode *last=r;
    while (last->right!=NULL)
    {
        last=last->right;
    }

    stackS *v=(stackS*)malloc(sizeof(stackS));
    stackS *a=(stackS*)malloc(sizeof(stackS));
    v->element=actual->right;
    v->next=NULL;
    while (v->element!=last)
    {
    while(actual->left!=NULL)
    {
        a=(stackS*)malloc(sizeof(stackS));
        a->element=actual->right;
        a->next=v;
        v=a;
        actual=actual->left;
    }
    actual->left=v->element;
    actual=actual->left;

    if (v->element!=last)
    {
        v=v->next;
    }

    }



    return r;
}

int main()
{
    FILE *f=fopen("hw.in","r");
    char c;
    treeNode *root=(treeNode*)malloc(sizeof(treeNode));
    stackS *top=(stackS*)malloc(sizeof(stackS));
    root->key='x';
    root->left=NULL;
    root->right=NULL;
    top->element=root;
    top->next=NULL;

    while((c=fgetc(f))!=EOF)
    {
        if (c!=' ')
        {
        if (isoperator(c)==0)
        {
            top=insertelement(top,c);

        }
        else
        {
            top=reforge(top,c);
            root=top->element;

        }
        }
    }
    fclose(f);

    printreePreorder(root);
    root=remake_prefix(root);
    root->right=NULL;

    printf("\n");
    treeNode *prev;
    treeNode *last;
    while (root!=NULL)
    {
        printf("%c ",root->key);
        prev=root;
        root=root->left;
        if(root!=NULL)
        {
        root->right=prev;
        }
        else
        {
         last=prev;
        }
    }
    printf("\n");
    while(prev!=NULL)
    {
        printf("%c ",prev->key);
        prev=prev->right;
    }
    return 0;
}
