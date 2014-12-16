#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    int val;
    struct st* next;
} stac;

void stInit (stac**,int);///initializes array and adds first element
void stInsert(stac**,int);///needs to be initialized, or be a NULL pointer
int stPop(stac**);
int stDequeue(stac **);///if all elements dequeued, the pointer becomes NULL

#endif // STACK_H_INCLUDED
