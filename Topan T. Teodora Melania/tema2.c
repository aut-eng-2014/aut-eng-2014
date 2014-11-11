#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *previous;
    struct node *next;
}
NodeT;

NodeT *last, *first;



void init()
{
    first=(NodeT*)malloc(sizeof(NodeT));
    last=(NodeT*)malloc(sizeof(NodeT));
    first->value=1;
    first->next=last;
    first->previous=NULL;
    last->value=9;
    last->previous=first;
    last->next=NULL;

}

void addfirst(int val)
{
    NodeT* newF=(NodeT*)malloc(sizeof(NodeT));
    newF->value=val;
    newF->next=first;
    newF->previous=NULL;
    first=newF;
}

void addlast(int val)
{
    NodeT* newN=(NodeT*)malloc(sizeof(NodeT));
    newN->value=val;
    last->next=newN;
    newN->next=NULL;
    newN->previous=last;
    last=newN;
}

void traversal()
{
    NodeT *temp=first;
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp=temp->next;

    }
}

void search(int val)
{
    NodeT* temp=first;
    while(temp!=NULL)
    {
        if(temp->value==val)
            printf("\nfound element: %d",temp->value);
        temp=temp->next;
    }
}

void rmov(int val)
{
    int OK=0;
    NodeT* temp=first;
    NodeT* prev=first;
    while(temp!=NULL)
    {
        if(temp->value==val)
        {
            if(temp==first)
            {
                first=first->next;
                OK=1;
            }
            else if(temp==last)
            {
                last=prev;
                last->next=NULL;
                OK=1;
            }
            else
            {
                prev->next=temp->next;
                OK=1;
            }
        }
        prev=temp;
        temp=temp->next;
    }
    if(OK==0)printf("\nelement %d not found for removal", val);
}

void sortin()
{
    NodeT* temp=first;
    int newS;
    int OK=0;
    while(OK==0)
    {
        OK=1;
        temp=first;
        while(temp->next!=NULL)
        {
            if(temp->value > temp->next->value)
            {
                newS = temp->value;
                temp->value = temp->next->value;
                temp->next->value = newS;
                OK=0;
            }
            temp=temp->next;
        }
    }
}
    int main()
{
    init();
    addfirst(3);
    addlast(8);
    traversal();
    search(8);
    rmov(6);
    printf("\nnew list is:");
    traversal();
    printf("\nsorted list:");
    sortin();
    traversal();
    return 0;
}

