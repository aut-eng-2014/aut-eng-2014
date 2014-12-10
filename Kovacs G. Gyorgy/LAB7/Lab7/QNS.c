
#include "QNS.h"

//===========Queue============

List* initQueue(){
    return NULL;
}

void NQ(List **Queue,int in){
    if (*Queue == NULL){
        *Queue = (List*) malloc(sizeof(List));
        (*Queue)->value = in;
        (*Queue)->next = NULL;
    }
    else{
        List *temp = (List*) malloc(sizeof(List));
        temp->value = in;
        temp->next = *Queue;
        *Queue = temp;
    }
}

int DQ(List **Queue){

    if (*Queue == NULL){
        printf("\n[W]: The queue has no elements.\n");
        return -1;
    }
    else if((*Queue)->next == NULL){
        int tempNum = (*Queue)->value;
        *Queue = NULL;
        return tempNum;
    }
    else{
        List *temp = *Queue;
        List *tempsFather = temp;
        while (temp->next != NULL){
            tempsFather = temp;
            temp = temp->next;
        }

        tempsFather->next = NULL;
        return temp->value;
    }
}

void printQueue(List **Queue){
    printf("Printing elements: [ ");
    if ((*Queue) == NULL){
        printf("VOID ].\n");
        return;
    }
    List *temp = *Queue;
    while (temp != NULL){
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("].\n");
}

//===========Stack============

List*  initStack(){
    return NULL;
}

void push(List **Stack, int in){
    if (*Stack == NULL){
        *Stack = (List*) malloc(sizeof(List));
        (*Stack)->value = in;
        (*Stack)->next = NULL;
    }
    else{
        List *temp = (List*) malloc(sizeof(List));
        temp->value = in;
        temp->next = Stack;
        *Stack = temp;
    }
}

int pop(List **Stack){
    if (*Stack == NULL){
        printf("\n[W]: The stack is empty.");
        return -1;
    }
    else{
        int tempNum = (*Stack)->value;
        *Stack = (*Stack)->next; //Memory leak.
        return tempNum;
    }
}

void printStack(List **Stack){
    printf("Printing elements: [ ");
    if (*Stack == NULL){
        printf("VOID\n");
        return;
    }
    List *temp = *Stack;
    while (temp != NULL){
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("].\n");
}

//============================

bool isEmpty(List **l){
    if (*l == NULL){
        return true;
    }
    else{
        return false;
    }
}
