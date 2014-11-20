#ifndef QNS_H
#define QNS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct{
    int value;
    struct List *next;
} List;

void NQ(List**,int);
void DQ(List**);
void printQueue(List**);

void push(List**,int);
void pop(List**);
void printStack(List**);

#endif
