/*
	Test from 2014.11.06
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int value;
    struct List *next;
} List;

List *Queue;
List *Stack;

//===========Queue============

void pushToQueue(int in){
    printf("Pushing %d to queue...",in);
    if (Queue == NULL){
        Queue = (List*) malloc(sizeof(List));
        Queue->value = in;
        Queue->next = NULL;
    }
    else{
        List *temp = (List*) malloc(sizeof(List));
        temp->value = in;
        temp->next = Queue;
        Queue = temp;
    }
    printf("done.\n");
}

void popFromQueue(){
    printf("Removing last element from queue...");
    int displayValue = 0;
    if (Queue == NULL){
        printf("\n[W]: The queue has no elements.\n");
    }
    else{
        List *temp = Queue;
        List *tempsFather = temp;
        while (temp->next != NULL){
            tempsFather = temp;
            temp = temp->next;
        }
        displayValue = temp->value;
        tempsFather->next = NULL;
        free(temp); // Does this solve the memory leak, or the garbage collector does this already?
    }
    printf("done(removed %d).\n",displayValue);
}

void printQueue(){
    printf("Printing elements: [ ");
    if (Queue == NULL){
        printf("VOID\n");
        return;
    }
    List *temp = Queue;
    while (temp != NULL){
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("].\n");
}

//===========Stack============

void pushToStack(int in){
    printf("Pushing %d to stack...",in);
    if (Stack == NULL){
        Stack = (List*) malloc(sizeof(List));
        Stack->value = in;
        Stack->next = NULL;
    }
    else{
        List *temp = (List*) malloc(sizeof(List));
        temp->value = in;
        temp->next = Stack;
        Stack = temp;
    }
    printf("done.\n");
}

void popFromStack(){
    printf("Removing first element from stack...");
    int removedValue = 0;
    if (Stack == NULL){
        printf("\n[W]: The stack is empty.");
    }
    else{
        removedValue = Stack->value;
        Stack = Stack->next; //Memory leak. 
    }
    printf("done(value %d).\n",removedValue);
}

void printStack(){
    printf("Printing elements: [ ");
    if (Stack == NULL){
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

int main(){
    pushToQueue(1);
    pushToQueue(2);
    pushToQueue(3);
    printQueue();
    popFromQueue();
    popFromQueue();
    printQueue();

    printf("\n\n");

    pushToStack(1);
    pushToStack(2);
    pushToStack(3);
    printStack();
    popFromStack();
    popFromStack();
    printStack();
    return 0;
}
