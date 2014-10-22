#ifndef DLLIST_H_INCLUDED
#define DLLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct nd  ///how can this be instantiated w/out classes?
{
    int val;
    struct nd* next,*prev;
} node;

node *f, *l;///fisrt,last
int lngth;  ///a length counder is needed to use the advantages of doubly linked lists
int iteratr; ///'cause iterator is reservered. will not retroactively implement it

void resetIteratr();
void moveIteratr(unsigned int pos);

void init (int first, int last); ///initializes list||call it before using the other functions
void addFirst(int);
void addLast (int);
void insrt(unsigned int pos, int value);
void insrtS(unsigned int pos,unsigned int argCount, ... );///can it be done without knowing argCount
void rmv(unsigned int pos);
void rmvS(unsigned int pos, int elementCount);///why isn't there overload in C?
int getNodeValue(int pos);
int getNextNodeValue();///based on the iterator
void printNode(unsigned int pos);
void printNodeS(unsigned int pos, int elementCount);
void printNextNode();
void printAll ();

#endif // DLLIST_H_INCLUDED
