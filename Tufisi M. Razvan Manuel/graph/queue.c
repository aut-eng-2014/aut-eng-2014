#include <stdlib.h>
#include <stdio.h>
#include "Simplelinkedlist.h"

nodeT* newNodeq(int k)
{
    nodeT *temp = (nodeT*)malloc(sizeof(nodeT));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

queueT *createQueue()
{
    queueT *q = (queueT*)malloc(sizeof(queueT));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(queueT *q, int k)
{
    nodeT *temp = newNodeq(k);
    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

nodeT *dequeue(queueT *q)
{
    if (q->front == NULL)
        return NULL;
    nodeT *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}
