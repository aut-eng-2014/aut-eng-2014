#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include "stack.h"

typedef struct he
{
    stac *first,*last;
} hashElement;

typedef struct ht
{
    hashElement * h;
    unsigned int hashTableLenght;
    int hFunction,maxHFuction;
} hashTable;


void htInit(hashTable *ht,int numberOfElements);
void htChangeHashFuction(hashTable *ht);
int htGetHashFunctionIndex(hashTable *ht);

char htInsert(hashTable *ht,char * newElement);///returns 0 on success, 1 on already existing element, 2 on memory allocation failure
void htInsertFast(hashTable *ht,char * newElement);///details in stack.h

int htCheck(hashTable *ht,char * inquiredValue); ///returns 0 on false and the length of the element on true
int htCheckDensity(hashTable *ht,char * inquiredValue);
int *htCheckDensityAll(hashTable *ht);
double htGetDensity(hashTable * ht);

int htGetArrayLength(hashTable *ht);///returns the number of elements the hashtable has
void htRemoveDuplicates(hashTable *ht);///~ caused by htInsertFast

char htRemove(hashTable *ht,char * elementToBeDeleted); /// returns 0 for non existent value, 1 otherwise
void htPurge(hashTable *ht);
///i made it instatiable for a change

#endif // HASH_H_INCLUDED
