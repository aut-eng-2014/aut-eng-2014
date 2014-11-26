#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include "QNS.h"

#define GRAPHSIZE 5

typedef enum{
        UNVISITED,
        VISITED
} VisitMark;

void clearGraph(int[GRAPHSIZE][GRAPHSIZE]);
void inputGraph(int[GRAPHSIZE][GRAPHSIZE]);

void printGraphMatrix(int[GRAPHSIZE][GRAPHSIZE]);
void traverseDFT(int[GRAPHSIZE][GRAPHSIZE]);
void traverseBFT(int[GRAPHSIZE][GRAPHSIZE]);

#endif // GRAPH_H
