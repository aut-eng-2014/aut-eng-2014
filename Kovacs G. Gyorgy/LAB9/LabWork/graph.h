#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include "QNS.h"

#define GRAPHSIZE 7

typedef enum{
        UNVISITED,
        VISITED
} VisitMark;

void bored(void);

void clearGraph(int[GRAPHSIZE][GRAPHSIZE]); // W + S
void printGraphMatrix(int[GRAPHSIZE][GRAPHSIZE]); // W + S

void inputGraph(int[GRAPHSIZE][GRAPHSIZE]); // S
void traverseDFT(int[GRAPHSIZE][GRAPHSIZE]); // S
void traverseBFT(int[GRAPHSIZE][GRAPHSIZE]); // S

void inputWGraph(int[GRAPHSIZE][GRAPHSIZE]);  // W
void traversePrim(int[GRAPHSIZE][GRAPHSIZE]); // W
void dijkstra(int[GRAPHSIZE][GRAPHSIZE]); // W

#endif // GRAPH_H
