
#include <stdlib.h>
#include <stdio.h>
#define MAXN 100 // max number of nodes

//create a struct to hold the nodes from the adjacency list
typedef struct node {

	int vertex;
	struct node *next;

}node;
// a list to hold all the heads of the lists
node *graph[MAXN];

// visited vector
int reach[MAXN];

void addEdge(int, int);
void printGraph(int);
void DFS(int);
void BFS(int);
