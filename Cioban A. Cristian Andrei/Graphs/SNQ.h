#include <stdlib.h>
#include <stdio.h>

// Queue & Stack
typedef struct QNS {

	int value;
	struct QNS *next;

}myQueue,myStack;


/* Queue functions */
myQueue *NQ(myQueue *, int);
myQueue *DQ(myQueue *);
void printQueue(myQueue *);

/* Stack Functions */
myStack *push(myStack *, int);
myStack *pop(myStack *);
void printStack(myStack *);
