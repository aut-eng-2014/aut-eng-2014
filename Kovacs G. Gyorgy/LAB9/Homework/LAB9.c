#include "graph.h"

int main(){
    //int adjacencyMatrix[GRAPHSIZE][GRAPHSIZE];
    //clearGraph(adjacencyMatrix);
    //inputWGraph(adjacencyMatrix);
    int adjacencyMatrix[GRAPHSIZE][GRAPHSIZE] = {{0,5,0,0,2,0,6},
                       {5,0,6,0,0,0,0},
                       {0,6,0,7,1,0,0},
                       {0,0,7,0,10,0,0},
                       {2,0,1,10,0,12,0},
                       {0,0,0,0,12,0,4},
                       {6,0,0,0,0,4,0}};

    printGraphMatrix(adjacencyMatrix);

    traversePrim(adjacencyMatrix);
    return 0;
}
