#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct st///ok, considering that it can both pop and deque its closer to a deque, than to a stack, but it cant accept an element to the beginning, so it isn't that either
{
    int val;
    struct st* next;
} stac;

void stInit (stac**,int);
void stPush(stac**,int);
int stPop(stac**);
int deQ(stac **);

#endif // STACK_H_INCLUDED
