#include "graph.h"

int main(){
    int g[GRAPHSIZE][GRAPHSIZE];// = {{0,1,4},{1,0,1},{4,1,0}};;
    int dist[GRAPHSIZE];

    inputWGraph(g);
    printf("Starting Node: ");
    int startinNode;
    scanf("%d",&startinNode);

    dijkstra(g,startinNode,dist);

    printArray(dist);
    printf("Distance: %d",distance(g,0,2));
    return 0;
}
