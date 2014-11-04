#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next, *prev;
} NodeT;
NodeT *first, *last;

void init ()
{
    first=(NodeT*) malloc(sizeof(NodeT));
    last=(NodeT*) malloc(sizeof(NodeT));
    first->prev=NULL;
    first->next=last;
    last->prev=first;
    last->next=NULL;
}

void addlast (int v)
{
    NodeT *newN=(NodeT*) malloc(sizeof(NodeT));
    newN->value=v;
    last->next=newN;
    newN->next=NULL;
    newN->prev=last;
    last=newN;
}

void addfirst (int v)
{
    NodeT *newN=(NodeT*) malloc(sizeof(NodeT));
    newN->value=v;
    newN->next=first;
    newN->prev=NULL;
    first->prev=newN;
    first=newN;
}

void search (int v)
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
    if(last->value==v)
    {
        printf("Am gasit valoarea %d in lista.", v);
        g=1;
    }
    if (g==0)
    {
        printf ("Valoarea %d nu se gaseste in lista.", v);
    }
}

void remove_value (int v)
{
    NodeT *current, *prev, *next;
    while (first->value==v)
    {
        current=first->next;
        current->prev=NULL;
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
            next->prev=prev;
            free(current);
        }
        else
            prev=current;
        current=next;
        next=current->next;
    }
    if (last->value==v)//now current=last
    {
        prev->next=NULL;
        free(last);
        last=prev;
    }
}

void bubble_sort()
{
    int swapped, aux;
    NodeT *one, *two;
    one=first;
    two=first->next;
    do
    {
        swapped=0;
        while (one->next!=NULL)
            if (one->value>two->value)
            {
                aux=one->value;
                one->value=two->value;
                two->value=aux;
                swapped=1;
            }
    }
    while (swapped==1);
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
