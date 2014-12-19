#include <stdlib.h>
#include "node.h"
#include "queue.h"

NodeT** queue_getFirst()
{
    static NodeT* queueFirst;
    return &queueFirst;
}

NodeT** queue_getLast()
{
    static NodeT* queueLast;
    return &queueLast;
}

void queue_push(void *value)
{
    if (*queue_getFirst() == NULL)
    {
        *queue_getFirst() = createNode(value);
        *queue_getLast() = *queue_getFirst();
    }
    else
    {
        NodeT *node = createNode(value);
        (*queue_getLast())->next = node;
        node->before = *queue_getLast();
        *queue_getLast() = (*queue_getLast())->next;
    }
}

void* queue_pop()
{
    if (*queue_getFirst() == NULL)
    {
        return NULL;
    }
    NodeT *node = *queue_getFirst();
    *queue_getFirst() = (*queue_getFirst())->next;
    if (*queue_getFirst() != NULL)
    {
        (*queue_getFirst())->before = NULL;
    }
    node->next = NULL;
    void *value = node->value;
    free(node);
    return value;
}

