#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Driver program to test above functions
int main()
{
    // create the graph given in above fugure
    int V = 5;
    GraphT* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);
   dfs(V,4,graph);
   bfs(V,6,graph);
    return 0;
}
