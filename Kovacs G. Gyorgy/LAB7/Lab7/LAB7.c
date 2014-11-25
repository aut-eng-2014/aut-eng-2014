#include "graph.h"

int main(){
    int Graph[GRAPHSIZE][GRAPHSIZE];
    clearGraph(Graph);
    inputGraph(Graph);

    printGraphMatrix(Graph);
    return 0;
}
