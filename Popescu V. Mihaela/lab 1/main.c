#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} NodeT;
NodeT *first, *last;

void init ()
{
    first=(NodeT*) malloc(sizeof(NodeT));
    last=(NodeT*) malloc(sizeof(NodeT));
    first->value=26;
    first->next=last;
    last->next=NULL;
}

void addlast (int v)
{
    NodeT *newN=(NodeT*) malloc(sizeof(NodeT));
    newN->value=v;
    last->next=newN;
    newN->next=NULL;
    last=newN;
}

void addfirst (int v)
{
    NodeT *newN=(NodeT*) malloc(sizeof(NodeT));
    newN->value=v;
    newN->next=first;
    first=newN;
}

void travers ()
{
    NodeT *temp=first;
    while (temp->next!=NULL)
        temp=temp->next;
}

void find (int v)
{
    NodeT *temp=first;
    int g=0;
    while (temp->next!=NULL)
    {
        if(temp->value==v)
        {
            printf("Am gasit valoarea %d in lista.", v);
            g=1;
        }
        temp=temp->next;
    }
    if (g==0)
        printf ("Valoarea %d nu se gaseste in lista.", v);
}

void remove_value (int v)
{
    NodeT *current, *prev, *next;
    while (first->value==v)
    {
        current=first->next;
        free(first);
        first=current;
    }
    prev=first;
    current=first->next;
    next=current->next;
    while (current->next!=NULL)
    {
        if (current->value==v)
        {
            prev->next=next;
            free(current);
        }
        else
            prev=current;
        current=next;
        next=current->next;
    }
    if (last->value==v)
    {
        prev->next=NULL;
        free(last);
        last=prev;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
