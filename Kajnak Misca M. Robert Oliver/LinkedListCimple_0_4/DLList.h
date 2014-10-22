#ifndef DLLIST_H_INCLUDED
#define DLLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct nd  ///how can this be instantiated w/out classes?
{                  ///e.g. I put every vatiable in a struct(including nd ofc), and give the type as a parameter for every function=>need to rewrite all functions, even more parameters=>there should be a better way
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
void insrtS(unsigned int pos,unsigned int argCount, ... );///can it be done without knowing argCount, I wonder
void rmv(unsigned int pos);
void rmvS(unsigned int pos, int elementCount);///why isn't there overload in C? -- maybe there is and I don't know about it
void rmvVal(int val);         ///removes first node w/ the value n
void rmvValS(int val);        ///removes all nodes w/ value n
int getNodeValue(int pos);
node* srch(int val);///returns the first node which has value n
int srchIndex(int val);///returns the index
int cnt();///count the nr of elements; should coincide w/ lngth
int getNextNodeValue();///based on the iterator
void srt();  ///Bubble sort
void printNode(unsigned int pos);
void printNodeS(unsigned int pos, int elementCount);
void printNextNode();
void printAll ();

void destruct(); ///frees all the nodes. ~destructor;

#endif // DLLIST_H_INCLUDED
