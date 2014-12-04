#include "graph.h"
#include "SnQ.h"

void addEdge(int i, int j) {

	//allocate memory for the node
	node *nodeN = (node*)malloc(sizeof(node));
	nodeN->vertex = j;
	nodeN->next = NULL;

	/* insert the node in the linked list number- i */
	if (graph[i] == NULL) /* if there are no other nodes insert the node */
	{
		graph[i] = nodeN;
	}
	else /* insert it at the end */
	{
		node *temp = graph[i];
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = nodeN;
	}
}

void printGraph(int n)
{
	int i;
	for (i = 0; i<n; i++)
	{
		printf("%d: ", i);
		node *temp = graph[i];
		while (temp != NULL)
		{
			printf("%d ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

void DFS(int i)
{
	node *p = NULL;
	myStack *stackP = NULL;
	stackP = push(stackP, i);
	reach[i] = 1;
	printf("%d ", i);

	int k = 0;

	while (stackP != NULL)
	{
		if (k == 0) p = graph[stackP->value];
		if (reach[p->vertex] == 0)
		{
			stackP = push(stackP,p->vertex);
			reach[p->vertex] = 1;
			printf("%d ", p->vertex);
			k = 0;

		}
		else
		{
			p = p->next;
			k = 1;
		}
		if (p == NULL)
		{
			stackP = pop(stackP);
			k = 0;
		}
	}

}

void BFS(int i)
{
	printf("%d ", i);
	reach[i] = 1;
	myQueue *root = NULL;
	root = NQ(root,i);
	node *p = graph[root->value];

	while (root != NULL)
	{
		p = graph[root->value];
		root = DQ(root);

		while (p != NULL)
		{

			if (reach[p->vertex] == 0)
			{
				printf("%d ", p->vertex);
				reach[p->vertex] = 1;
				root = NQ(root,p->vertex);
			}
			p = p->next;
		}
	}

}
