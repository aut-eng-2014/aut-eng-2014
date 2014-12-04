#ifndef FUNCTIONS4GRAPHS_H_INCLUDED
#define FUNCTIONS4GRAPHS_H_INCLUDED

#include "stack.h"

void purge(char *a,int n);
char isAllVisited(char *a,int n);
int * BFS(int **a,int n,int startNode);
stac *DFS(int **a,int n,int startNode);
void DFSrec(int **a,int n, int startNode, char *boolArray,stac ** visitedList);

typedef struct edgelist
{
    int first,next;
    int val;
} edgeList;

edgeList* Prims(int * edgeSequence, int ** graph, int maxElement, int startElement);

#endif // FUNCTIONS4GRAPHS_H_INCLUDED
