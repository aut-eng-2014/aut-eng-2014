#ifndef STACK_HEADER
#define STACK_HEADER

#include "node.h"

/* returns the pointer to the top of the stack */
NodeT** stack_get();

/* pushes on the stack a pointer to the value */
void stack_push(void *value);

/* returns the popped pointer to the value */
void* stack_pop();

#endif
