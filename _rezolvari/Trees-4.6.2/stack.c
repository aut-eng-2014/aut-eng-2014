#include "functions.h"

NodeS* peek(){
    return head;
}

void pop(){
    if(head!=NULL)
        head = head->next;
}
void push(char* content){
    NodeS * newHead = (NodeS*) malloc(sizeof(NodeS));
    newHead->content = content;
    newHead->next = head;
    head=newHead;
}
