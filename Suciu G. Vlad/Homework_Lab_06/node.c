#include <stdlib.h>
#include "node.h"

NodeT* createNode(void *value)
{
    NodeT *node = (NodeT*) malloc(sizeof(NodeT));
    node->before = NULL;
    node->next = NULL;
    node->value = value;
    return node;
}
