
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
        printf("\t%d.\n\tNode 1: ",i);
        scanf("%d",&a);
        printf("\tNode 2: ");
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

/*
1  procedure DFS-iterative(G,v):
2      let S be a stack
3      S.push(v)
4      while S is not empty
5            v ← S.pop()
6            if v is not labeled as discovered:
7                label v as discovered
8                for all edges from v to w in G.adjacentEdges(v) do
9                    S.push(w)
*/

void traverseDFT(int g[GRAPHSIZE][GRAPHSIZE]){
    int startingNode;
    printf("\n\tDepth Fist Traversal:\n\tStarting Node: ");
    scanf("%d",&startingNode);

    VisitMark mark[GRAPHSIZE];
    List *Stack = initStack();
    int i,j;

    for (i = 0; i < GRAPHSIZE; i++){
            mark[i] = UNVISITED; // For starters, mark all nodes as UNVISITED
    }

    push(&Stack,startingNode);
    while (!isEmpty(&Stack)){
        system("pause");
        printStack(&Stack);
        int temp = pop(&Stack);
        printf("%d ",temp);
        if (mark[temp] == UNVISITED){
            mark[temp] = VISITED;
            for (j = 0; j < GRAPHSIZE; j++){
                if (g[j][temp] == 1){
                    printf("Pushing %d\n",j);
                    push(&Stack,j);
                    printStack(&Stack);
                }
            }
        }
    }
}

void traverseBFT(int g[GRAPHSIZE][GRAPHSIZE]){
    int startingNode;
    printf("\n\tBreadth First Traversal:\n\tStarting Node: ");
    scanf("%d",&startingNode);

    VisitMark mark[GRAPHSIZE]; // to know which nodes to add
    List *Q = initQueue();
    int i,j;

    for (i = 0; i < GRAPHSIZE; i++){
            mark[i] = UNVISITED; // For starters, mark all nodes as UNVISITED
    }

    mark[startingNode] = VISITED;

    NQ(&Q,startingNode);

    while (!isEmpty(&Q)){
        int temp = DQ(&Q);
        printf("%d ",temp);
        for (j = 0; j < GRAPHSIZE; j++){
                if (g[j][temp] == 1){
                    if (mark[j] == UNVISITED){
                        mark[j] = VISITED;
                        NQ(&Q,j);
                    }
                }
        }
    }
}
