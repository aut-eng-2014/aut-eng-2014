#include "functions.h"

QueueN *peek(){
    return head;
}

void enqueue(char *content){

    if(head==NULL){
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
void dequeue(){
    if(head!=NULL){
        head = head->next;
    }
}
