#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st///stack or queue is more efficient for insertion, but less for deletion
{
    struct st * next;
    char* val;
} stac;

void sInsertFast(stac **last,char *value);///does not chack for already existing element||Useful if fast insertion is required, but the storage can be optimized at a later time, before the quieries
char sInsert(stac** first, stac** last,char *value);///stac last should be the last element from the stack
                                        ///returns 0 on success, 1 on already existing element, 2 on memory allocation failure
//void sInit();///this should be resolved in hash.c, i.e. all val pointers should be set to NULL
int sCheck(stac *first,char *value);
int sLength(stac *first);///returns the number of elements in the respective stack
void sRemoveDuplicates(stac * first,stac ** last);
char sRemove(stac ** first,char *value);
void sWipe(stac **first); ///Caution: do not read outloud

#endif // STACK_H_INCLUDED
