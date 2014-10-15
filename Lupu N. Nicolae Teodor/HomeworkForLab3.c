#include <stdio.h>
#include <stdlib.h>

typedef struct NodeT
{
    int value;
    struct node *next;
    struct node *prev;
}NodeT;


NodeT *first,*last;

void init(int val1, int val2)
{
    first=(NodeT*)malloc(sizeof(NodeT));
    last=(NodeT*)malloc(sizeof(NodeT));

    first->next=last;
    last->prev=first;

    last->next=NULL;
    first->prev=NULL;

    first->value=val1;
    last->value=val2;
}

void traversal()
{
    NodeT *t;
    t=(NodeT*)malloc(sizeof(NodeT));

    last->next=NULL;
    first->prev=NULL;

    printf("\n The elements of the list are now: ");

    for(t=first;t!=NULL;t=t->next)
    {
        printf("%d ", t->value);
    }

    printf("\n");
}

void add1 (int val)
{
    NodeT *t;
    t=(NodeT*)malloc(sizeof(NodeT));

    last->next=NULL;
    first->prev=NULL;

    if(first==NULL)
    {
        first=last=t;
        t->next=t->prev=NULL;
        t->value=val;
    }

    else
    {
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
        t->value=val;
    }
}

void add2 (int val)
{
    NodeT *t;
    t=(NodeT*)malloc(sizeof(NodeT));

    last->next=NULL;
    first->prev=NULL;

    if(first==NULL)
    {
        t->value=val;
        first=last=t;
        t->next=t->prev=NULL;
    }
    else
    {
        t->value=val;
        last->next=t;
        t->prev=last;
        last=t;
    }
}

void clear()
{
    NodeT *t;
    t=(NodeT*)malloc(sizeof(NodeT));

    last->next=NULL;
    first->prev=NULL;

    t=first;
    first=first->next;
    free(t);

    if(first==NULL)
    {
        last=NULL;
    }

    else
    {
        first->prev=NULL;
    }
}


void search(int val)
{
    NodeT *t;
    t=(NodeT*)malloc(sizeof(NodeT));

    int n=0;

    last->next=NULL;
    first->prev=NULL;

    for(t=first;t!=NULL;t=t->next)
    {
        if(t->value==val)
        {
            n++;
        }
    }
    printf("This list contains %d elements with this value %d",n,val);
    printf("\n");
}

int main()
{
    int x,value,val1,val2;

    printf("Enter the first 2 values: \n");
    printf("First Value: ");
    scanf("%d",&val1);
    printf("\nSecond Value: ");
            scanf("%d",&val2);
            init(val1,val2);
            traversal();
    printf("Please insert the values you want to insert at the begining and at the end: ");
            scanf("%d", &value);
            add1(value);
            scanf("%d", &value);
            add2(value);
            traversal();
    printf(" Please insert the value you want searched from the list: ");
            scanf("%d", &value);
            search(value);
    printf("Now the first element will be removed");
    clear(value);
            traversal();


}

