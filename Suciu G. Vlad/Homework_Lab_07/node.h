#ifndef NODE_HEADER
#define NODE_HEADER

typedef struct node {
    void *value;
    struct node *before;
    struct node *next;
} NodeT;

/* returns a pointer to a new node based on value */
NodeT* createNode(void *value);

#endif

