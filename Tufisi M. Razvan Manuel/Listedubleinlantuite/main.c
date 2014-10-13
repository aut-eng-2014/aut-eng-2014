#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
    int key;
    struct node* prev;
    struct node* next;
} nodeT;

nodeT *first,*last;

void init()
{
    first = 0;
    last = 0;
    first=(nodeT*)malloc(sizeof(nodeT));
    last=(nodeT*)malloc(sizeof(nodeT));

    first->key=6;
    first->next=last;
    first->prev=NULL;
    last->key=5;
    last->prev=first;
    last->next=NULL;
}

void addfirst(int key)
{
    nodeT *newN=(nodeT*)malloc(sizeof(nodeT));
    newN->prev=NULL;
    first->prev=newN;
    newN->next=first;
    newN->key=key;

    first=newN;


}

void addlast(int key)
{
    nodeT *newN=(nodeT*)malloc(sizeof(nodeT));
    last->next=newN;
    newN->prev=last;
    newN->next=NULL;
    newN->key=key;
    last=last->next;

}

nodeT *finde(int key)
{
    nodeT *temp;
    temp = first;
    while ( temp != NULL )
        if( (temp->key== key))
        {
            return temp;
        }
        else
            temp =temp ->next ;
    return NULL;
}

void remov(int key)
{
    nodeT *temp=(nodeT*)malloc(sizeof(nodeT));
    temp->key=key;

    if ((first == NULL) && (last ==NULL))
    {
        free(temp);
    }
    else if(key == first->key)
    {
        first = last -> next;
        first -> prev =NULL;
        free(temp);
    }
    else if (key == last->key)
    {
        last = last -> prev;
        last -> next = NULL;
        free(temp);
    }
    else
    {
        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
        free(temp);
    }

}




void afis()
{
    nodeT *temp;
    temp=first;
    while (temp != 0)
    {
        printf("%d  ",temp->key);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    init();
    addfirst(7);
    addlast(9);


    afis();

    nodeT *b=finde(9);
    if(b!=NULL)
        printf("%d",b->key);
    else
        printf("Value not found");
    printf("\n");
    remov(9);
    afis();


    return 0;
}
