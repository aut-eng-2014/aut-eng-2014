#ifndef QNS_H
#define QNS_H

#include <stdlib.h>
#include <stdio.h>

typedef enum{
    false,
    true
} bool;

typedef struct{
    int value;
    struct List *next;
} List;

List* initQueue(void);
void NQ(List**,int);
int DQ(List**);
void printQueue(List**);

List* initStack(void);
void push(List**,int);
int pop(List**);
void printStack(List**);

bool isEmpty(List**);

#endif
