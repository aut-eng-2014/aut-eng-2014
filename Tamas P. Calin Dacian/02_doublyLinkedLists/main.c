#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int val;
    struct node *next, *prev;
} NodeT;

NodeT *first, *last;

void init()
{
    first=(NodeT*)malloc(sizeof(NodeT));
    last=(NodeT*)malloc(sizeof(NodeT));
    first->prev=NULL;
    first->val=1;
    first->next=last;

    last->prev=first;
    last->val=2;
    last->next=NULL;
}

void traversal(char* direction)
{
    if (strcmp(direction,"forward")==0)
        {
            printf("Going forward\n");
            NodeT *temp=first;
            while (temp!=NULL)
            {
                printf("%d\n", temp->val);
                temp=temp->next;
            }
        }
    else if (strcmp(direction,"backward")==0)
        {
            printf("Going backward\n");
            NodeT *temp=last;
            while (temp!=NULL)
            {
                printf("%d\n", temp->val);
                temp=temp->prev;
            }
        }
}

void addNode(int value, int position)
{
    NodeT *newN;
    newN=(NodeT*)malloc(sizeof(NodeT));
    newN->val=value;

    int c=nrOfElements(); ///number of nodes

    if (position==1)
        {
            newN->next=first;
            newN->prev=NULL;
            first->prev=newN;
            first=newN;
        }
    else
    if (position==c)
        {
            newN->next=NULL;
            last->next=newN;
            newN->prev=last;
            last=newN;
        }
    else
    {
        NodeT *temp=first;
        int i;
        for (i=0; i<position-1; i++)
            temp=temp->next;
        newN->next=temp;
        newN->prev=temp->prev;
        temp->prev->next=newN;
        temp->prev=newN;

    }
}

NodeT* findValue(int value)
{
    NodeT *temp=first;
    int k=0;
    while (temp!=NULL)
    {
        if (value == temp->val)
           {k=1; break;}
        temp=temp->next;
    }
    if (k != 0)
        printf("the value %d has been found\n", value);
    else printf("the value %d has NOT been found\n", value);
    return temp; //returns a pointer to the node
}

void removeElement(int value)
{
    NodeT *temp=findValue(value);
    if (temp==first)
    {
        first=temp->next;
        first->prev=NULL;
        free(temp);

    }
    else if (temp==last)
    {
        last=temp->prev;
        last->next=NULL;
        free(temp);
    }
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }

}

int nrOfElements()
{
    int c=0;
    NodeT *temp=first;
    while (temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
return c;
}

NodeT *partition(NodeT *start, NodeT *end)
{
    NodeT *pivot=end, *pIndex=start;
    int tempint;

    while (start<end)
    {
        if (start->val <= pivot->val)
        {
            tempint=start->val;
            start->val=pIndex->val;
            pIndex->val=tempint;
            pIndex=pIndex->next;
        }
        start=start->next;
    }
    tempint=pIndex->val;
    pIndex->val=end->val;
    end->val=tempint;

    return pIndex;
}

void quick_sort(NodeT *start, NodeT *end)
{
    if (start<end)
    {
        NodeT *partIndex=partition(start,end);
        quick_sort(start, partIndex->prev);
        quick_sort(partIndex->next, end);
    }
}

int main()
{
    init();

    addNode(3,1);
    addNode(7,3);
    addNode(18,4);
    addNode(2,5);

    removeElement(2);

    traversal("backward");
    traversal("forward");

    findValue(99);

    int n=nrOfElements();
    printf("\nthe list has %d elements\n",n);

    quick_sort(first,last);
    traversal("forward");

    return 0;
}
