#ifndef LIST_HEADER
#define LIST_HEADER

#include "node.h"

typedef struct list_header {
    int size;
    struct node *first;
} ListT;

/* generates a list */
ListT* list_header();

/* returns node by position */
NodeT* list_node(ListT* header, int pos);

/* returns value by position */
void* list_get(ListT* header, int pos);

/* 1 if it has the value, 0 if not */
char list_contains(ListT* header, void* value);

/* add new value to the list */
void list_add(ListT* header, void* value);

/* removes duplicate values in the list */
void list_unique(ListT* header);

/* remove value from the list */
void* list_remove(ListT* header, int pos);

#endif
