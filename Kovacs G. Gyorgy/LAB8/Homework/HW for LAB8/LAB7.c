#include "graph.h"

int main(){
    int adjacencyMatrix[GRAPHSIZE][GRAPHSIZE];
    clearGraph(adjacencyMatrix);
    inputGraph(adjacencyMatrix);

    printGraphMatrix(adjacencyMatrix);

    traverseBFT(adjacencyMatrix);
    traverseDFT(adjacencyMatrix);
    return 0;
}
