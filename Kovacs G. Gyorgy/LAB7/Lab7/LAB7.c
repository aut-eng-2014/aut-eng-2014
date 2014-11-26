#include "graph.h"

int main(){
    int Graph[GRAPHSIZE][GRAPHSIZE];
    clearGraph(Graph);
    inputGraph(Graph);

    printGraphMatrix(Graph);

    traverseBFT(Graph);
    traverseDFT(Graph);
    return 0;
}
