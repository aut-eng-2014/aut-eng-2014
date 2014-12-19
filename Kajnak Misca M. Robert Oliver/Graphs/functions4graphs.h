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

edgeList* Prims(int * edgeSequence, int ** graph, int graphSize, int startElement);

typedef struct singlyLinkedList
{
    struct singlyLinkedList* next;
    int val;
} sll;

typedef struct pth
{
    int totalDistance;
    int vCount;

    sll *itrator,*first;///vertexes is correct as well
} path;


int* Dijskra(int**graph,int graphSize,int startElement);///returns the length vector
#endif // FUNCTIONS4GRAPHS_H_INCLUDED
