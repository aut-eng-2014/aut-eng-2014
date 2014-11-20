#include "QNS.h"

#define GRAPHSIZE 6
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
        printf("%d. Edge:\nI = ",i);
        scanf("%d",&a);
        printf("J = ");
        scanf("%d",&b);

        g[a][b] = 1;
        g[b][a] = 1;
        printf("Edge (%d,%d) added.\n\n",a,b);
    }
}

void traverseDFT(int g[GRAPHSIZE][GRAPHSIZE]){
    //TODO code eet
}

void traverseBFT(int g[GRAPHSIZE][GRAPHSIZE]){
    //TODO also code eet
}

int main(){
    int Graph[GRAPHSIZE][GRAPHSIZE];
    clearGraph(Graph);
    inputGraph(Graph);

    return 0;
}
