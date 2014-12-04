#include "graph.h"



int main(){
    system("COLOR B");

    int adjacencyMatrix[GRAPHSIZE][GRAPHSIZE];
    clearGraph(adjacencyMatrix);
    inputWGraph(adjacencyMatrix);
    printGraphMatrix(adjacencyMatrix);

    dijkstra(adjacencyMatrix);
    return 0;
}
