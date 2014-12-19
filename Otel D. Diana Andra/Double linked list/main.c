/* Homework: init(), add first, add last, search, count, remove, sort ascending, sort descending */

#include <stdio.h>
#include <stdlib.h>

typedef struct doublelist

{
    struct doublelist *prev;
    struct doublelist *next;
    int value;
} ListT;

ListT* first;  //first element
ListT* last;  //last element

void init()
{
    first=(ListT*)malloc(sizeof(ListT));
    last=(ListT*)malloc(sizeof(ListT));
    first->prev=NULL;
    first->next=last;
    last->prev=first;
    last->next=NULL;
}

void AddFirst(int val)
{
    ListT* NewFirst=(ListT*)malloc(sizeof(ListT));
    NewFirst->value=val;
    first->prev=NewFirst;
    NewFirst->prev=NULL;
    NewFirst->next=first;
    first=NewFirst;
}

void AddLast(int val)
{
    ListT* NewLast=(ListT*)malloc(sizeof(ListT));
    NewLast->value=val;
    NewLast->prev=last;
    last->next=NewLast;
    NewLast->next=NULL;
    last=NewLast;
}

//temp will be used for temporary storage

void Find(int val)
{
    ListT *temp=(ListT*)malloc(sizeof(ListT));
    temp=first;
    while(temp!=NULL)
    {
        if(temp->value==val)
        {
            printf("The element has been found./n");
        }
        else temp=temp->next;
    }
}

void RemoveElement(int val)
{
    ListT *temp=(ListT*)malloc(sizeof(ListT));
    ListT *deleted=(ListT*)malloc(sizeof(ListT));  //for the element I want to remove
    temp=first;
    deleted->value=0;
    while(temp!=NULL)
    {
        if(temp->value==val)
        {
            deleted=temp;
            if(temp->next!=NULL)
                temp->next->prev = temp->prev;
        }
        else
        {
            last = temp->prev;
            if(last!=NULL)
                last->next = NULL;
        }
        if(temp->prev!=NULL)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            first = temp->next;
            if(first!=NULL)
                first->prev = NULL;
        }
        free(deleted);
    }
    temp=temp->next;
}

void count()
{
    int total=0; // the total number of elements
    ListT *temp=(ListT*)malloc(sizeof(ListT));
    temp=first;
    while(temp!=NULL)
    {
        total++;
        temp=temp->next;
    }
}

void sort_asc()
{
    //temp will be the current node, temp_prev will be the previous one and temp_next the following one
    ListT *temp=(ListT*)malloc(sizeof(ListT));
    ListT *temp_prev=(ListT*)malloc(sizeof(ListT));
    ListT *temp_next=(ListT*)malloc(sizeof(ListT));
    temp=first;
    while(temp!=NULL)
    {
        temp_prev=temp->prev;
        temp_next=temp->next;
        if(temp->value > temp->next->value)
        {
            if(temp_prev!=NULL)
            {
                temp_prev->next=temp_next;
            }
            temp->next = temp_next->next;
            temp->prev = temp_next;
            temp_next->next = temp;
            temp_next->prev = temp_prev;
        }
    }
}

void sort_desc()
{
    ListT *temp=(ListT*)malloc(sizeof(ListT));
    ListT *temp_prev=(ListT*)malloc(sizeof(ListT));
    ListT *temp_next=(ListT*)malloc(sizeof(ListT));
    temp=first;
    while(temp!=NULL)
    {
        temp_prev=temp->prev;
        temp_next=temp->next;
        if(temp->value < temp->next->value)
        {
            if(temp_prev!=NULL)
            {
                temp_prev->next=temp->next;
            }
            temp->next = temp_next->next;
            temp->prev = temp_next;
            temp_next->next = temp;
            temp_next->prev = temp_prev;
        }
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}

