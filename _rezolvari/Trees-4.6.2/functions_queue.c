#include "functions.h"

/**
* Returns the first element in the queue
*/
QueueN *peek()
{
    return head;
}

/**
* Introduces an element with content 'content' at the top of the queue
*/
void enqueue(char *content)
{

    if(head==NULL)
    {
        head = (QueueN*)malloc(sizeof(QueueN));
        head-> content = content;
    }
    else if(last==NULL)
    {
        last = (QueueN*)malloc(sizeof(QueueN));
        last->content= content;
        head->next = last;
        last->next=NULL;
    }
    else
    {
        QueueN *node = (QueueN*) malloc(sizeof(QueueN));
        node->content= content;

        node->next = NULL;
        last->next = node;
        last = node;
    }
}

/**
* Removes the first element in the queue
*/
void dequeue()
{
    if(head!=NULL)
    {
        head = head->next;
    }
}
