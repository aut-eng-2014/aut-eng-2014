#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "Simplelinkedlist.h"

// function to create a new adjacency list node
AdjListNodeT* newAdjListNode(int dest)
{
    AdjListNodeT* newNode =(AdjListNodeT*) malloc(sizeof(AdjListNodeT));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

//  function that creates a graph of V vertices
GraphT* createGraph(int V)
{
    GraphT* graph = (GraphT*) malloc(sizeof(GraphT));
    graph->V = V;

    // create an array of adjacency lists. size of array will be V
    graph->array = ( AdjListT*)malloc(V *sizeof( AdjListT));

    // initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// adds an edge to an undirected graph
void addEdge(GraphT* graph, int src, int dest)
{
    // sdd an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    AdjListNodeT* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// A utility function to print the adjacenncy list representation of graph
void printGraph(GraphT* graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        AdjListNodeT* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

void dfs(int V, int src,GraphT* graph)
{
    int mark[V] ; /* for marking visited nodes */
    nodeT *root=NULL ;/* stack of nodes */
    nodeT *v=NULL;
    int i; /* nodes */
    for(i=0; i<V; i++ )
        mark[i] = 0;
    mark[src] =1; /* mark source node visited */
    push(&root,src);
    AdjListNodeT* pCrawl = graph->array[i].head;
    while (pCrawl)
    {
        pCrawl = pCrawl->next;
    }
    while (!root)
    {
        v->data=peek(root);
        printf("%d",v->data);
        if(!mark[i])
            {
                mark[i] = 1;
                push(&root,i);
            }
        else pop(&root);
    }
}


void bfs(int V,int src, GraphT* graph)
{
    nodeT *v;
    int i,visited[V];/* for marking visited nodes */
    for( i = 0; i < V; i++)
        visited[i] = 0;
    queueT *q=createQueue() ;/* queue of nodes */
    visited[src] = 1;/* mark source node visited */
    enqueue(q,src) ;
    AdjListNodeT* pCrawl = graph->array[i].head;
    while (pCrawl)
    {
        pCrawl = pCrawl->next;
    }
    while(!q)
    {
         v=dequeue(q);
        printf("%d",v->data);
        for(i=pCrawl->dest; i!= 0; ++i)
        {
            if(!visited[i])
            {
                visited[i] = 1;
                enqueue(q,i);
            }
        }
    }
}
