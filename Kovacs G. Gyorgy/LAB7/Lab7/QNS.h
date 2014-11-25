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

void NQ(List**,int);
int DQ(List**);
void printQueue(List**);

void push(List**,int);
int pop(List**);
void printStack(List**);

#endif
