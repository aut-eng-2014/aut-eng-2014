#include "graph.h"

void clearGraph(int g[GRAPHSIZE][GRAPHSIZE]){
    int i,j;
    for (i = 0; i < GRAPHSIZE; i++){
        for (j = 0; j < GRAPHSIZE; j++){
                g[i][j] = 0;
        }
    }
}

void inputGraph(int g[GRAPHSIZE][GRAPHSIZE]){
    printf("\n\tInputting Edges: \n");
    printf("\tHow many edges do you wish to add? ans = ");
    int numberOfEdges = 0;
    scanf("%d",&numberOfEdges);

    int i;
    int a,b;
    for (i = 0; i < numberOfEdges; i++){
        printf("\t%d.\n\tI = ",i);
        scanf("%d",&a);
        printf("\tJ = ");
        scanf("%d",&b);

        g[a][b] = 1;
        g[b][a] = 1;
        printf("\tEdge (%d,%d) added.\n\n",a,b);
    }
}

void printGraphMatrix(int g[GRAPHSIZE][GRAPHSIZE]){
    int i,j;
    printf("\n");
    for (i = 0; i < GRAPHSIZE; i++){
        printf("\t| ");
        for (j = 0; j < GRAPHSIZE; j++){
                printf("%d ",g[i][j]);
        }
        printf("|\n");
    }
}

void traverseDFT(int g[GRAPHSIZE][GRAPHSIZE]){
    //TODO code eet
}

void traverseBFT(int g[GRAPHSIZE][GRAPHSIZE], int sourceR, int sourceC){
    VisitMark mark[GRAPHSIZE][GRAPHSIZE];
    List *Q;
    int i,j,v,w;

    for (i = 0; i < GRAPHSIZE; i++){
        for (j = 0; j < GRAPHSIZE; j++){
            mark[i][j] = UNVISITED;
        }
    }

    mark[sourceR][sourceC] = VISITED;
    NQ(Q,g[sourceR][sourceC]);
    while (!isEmpty(Q)){
        v = DQ(Q);
        for (i = 0; i < GRAPHSIZE; i++){
            for (j = 0; j < GRAPHSIZE; j++){
                if ()
            }
        }
    }
}
