#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next,*prev;
}
NodeT;
NodeT *first, *last;
void init();
void addlast(int value);
void addfirst(int value);
void travers();
void Find(int value);
void Remove(int value);


int main()

{
    init();
    addfirst(3);
    addlast(8);
    addfirst(6);
    addlast(1);
    travers();
    fin(8);
    rem(5);
    rem(2);
    printf("\nnoua lista este:\n");
    travers();
    printf("\n lista sortata:\n");

    sor();
    travers();

    return 0;
}

void init()
{
    first=(NodeT*)malloc(sizeof(NodeT));
    last=(NodeT*)malloc(sizeof(NodeT));
    last->value=2;
    first->value=5;
    first->next=last;
    last->next=first;
    first->prev=NULL;
    last->prev=first;

}

void addlast(int value)
{
    NodeT* newN=(NodeT*)malloc(sizeof(NodeT));
    newN->value=value;
    last->next=newN;
    newN->prev=last;
    newN->next=NULL;
    last=newN;
}
void travers()
{
    NodeT *temp=first;
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp=temp->next;

    }
}
void addfirst(int value)
{
    NodeT* newF=(NodeT*)malloc(sizeof(NodeT));
    newF->value=value;
    newF->next=first;
    newF->prev=NULL;
    first=newF;
}
void fin(int value)
{
    NodeT* temp=first;
    while(temp!=NULL)
    {
        if(temp->value==value)
            printf("\nam gasit elementul: %d\n",temp->value);
         temp=temp->next;
    }
}

void rem(int value)
{
    NodeT* temp=first;
    NodeT* prev=first;
    while(temp!=NULL)
    {
        if(temp->value==value)
        {
            if(temp==first)
            {
                first=first->next;
            }
            else if(temp==last)
            {
                last=prev;
                last->next=NULL;
            }
            else
                prev->next=temp->next;
        }
        prev=temp;
        temp=temp->next;
    }

}
void sor()
{
     int aux;
     char ok=0;


    while(!ok)
    {
        ok=1;
    NodeT* temp=first;
    while(temp!=last)
    {
        if(temp->value>temp->next->value)
           {
            aux=temp->value;
            temp->value=temp->next->value;
            temp->next->value=aux;
            ok=0;
           }
           temp=temp->next;
    }
    }

}
