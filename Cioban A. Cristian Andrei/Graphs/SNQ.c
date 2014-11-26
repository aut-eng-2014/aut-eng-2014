#include "SnQ.h"

/*--------- Queue -------------*/

myQueue *NQ(myQueue *node, int value) {

	if (node == NULL) {
		node = (myQueue *)malloc(sizeof(myQueue));
		node->value = value;
		node->next = NULL;
	}
	else {
		myQueue *temp = (myQueue *)malloc(sizeof(myQueue));
		temp->value = value;
		temp->next = node;
		node = temp;
	}
}

myQueue *DQ(myQueue *node) {

	if (node == NULL) {
		printf("\n queue empty \n");
	}
	else {
		myQueue *temp = node;
		myQueue *tempFather = temp;
		if (temp->next == NULL) {
			temp = NULL;
			node = temp;
		}
		else{
			while (temp->next != NULL) {
				tempFather = temp;
				temp = temp->next;
			}
			tempFather->next = NULL;
		}
	}

}


void printQueue(myQueue *node) {

	if (node == NULL) {
		printf("\n queue empty \n");
	}
	else {
		while (node != NULL) {
			printf("%d ", node->value);
			node = node->next;
		}
		printf("\n");
	}

}

/*--------- Stack -------------*/

myStack *push(myStack *node, int value) {

	if (node == NULL) {
		node = (myStack *)malloc(sizeof(myStack));
		node->value = value;
		node->next = NULL;
	}
	else {
		myStack *temp = (myStack *)malloc(sizeof(myStack));
		temp->value = value;
		temp->next = node;
		node = temp;
	}
}

myStack *pop(myStack *node) {

	if (node == NULL) {
		printf("\n stack empty \n");
	}
	else {
		myStack *temp = node;
		temp = temp->next;
		node = temp;
	}

}

void printStack(myStack *node) {

	if (node == NULL) {
		printf("\n stack empty \n");
	}
	else {
		while (node != NULL) {
			printf("%d ", node->value);
			node = node->next;
		}
		printf("\n");
	}

}
