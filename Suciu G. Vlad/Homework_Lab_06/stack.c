#include <stdlib.h>
#include "stack.h"
#include "node.h"

NodeT** stack_get()
{
    static NodeT* stack;
    return &stack;
}

void stack_push(void *value)
{
    if (*stack_get() == NULL)
    {
        *stack_get() = createNode(value);
    }
    else
    {
        NodeT *node = createNode(value);
        (*stack_get())->next = node;
        node->before = *stack_get();
        *stack_get() = (*stack_get())->next;
    }
}

void* stack_pop()
{
    if (*stack_get() == NULL)
    {
        return NULL;
    }
    NodeT *node = *stack_get();
    *stack_get() = (*stack_get())->before;
    if (*stack_get() != NULL)
    {
        (*stack_get())->next = NULL;
    }
    node->before = NULL;
    void *value = node->value;
    free(node);
    return value;
}

