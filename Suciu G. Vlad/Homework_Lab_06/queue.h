#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include "node.h"

/* returns the pointer to the front of the queue */
NodeT** queue_getFirst();

/* returns the pointer to the end of the queue */
NodeT** queue_getLast();

/* pushes on the queue a pointer to the value */
void queue_push(void *value);

/* returns the popped pointer to the value */
void* queue_pop();

#endif
