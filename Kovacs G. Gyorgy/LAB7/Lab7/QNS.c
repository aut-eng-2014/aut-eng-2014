#include "QNS.h"

//===========Queue============

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

void DQ(List **Queue){

    if (*Queue == NULL){
        printf("\n[W]: The queue has no elements.\n");
    }
    else{
        List *temp = *Queue;
        List *tempsFather = temp;
        while (temp->next != NULL){
            tempsFather = temp;
            temp = temp->next;
        }

        tempsFather->next = NULL;
        free(temp); // Does this solve the memory leak, or the garbage collector does this already?
    }
}

void printQueue( List **Queue){
    printf("Printing elements: [ ");
    if (*Queue == NULL){
        printf("VOID\n");
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

void pop(List **Stack){
    if (*Stack == NULL){
        printf("\n[W]: The stack is empty.");
    }
    else{
        *Stack = (*Stack)->next; //Memory leak.
    }
}

void printStack(List **Stack){
    printf("Printing elements: [ ");
    if (*Stack == NULL){
        printf("VOID\n");
        return;
    }
    List *temp = Stack;
    while (temp != NULL){
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("].\n");
}

//============================
