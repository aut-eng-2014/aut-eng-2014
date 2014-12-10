
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
        printf("\t%d.\n\tNode 1: ",i + 1);
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
                printf("%3d ",g[i][j]);
        }
        printf("|\n");
    }
}

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
        int temp = pop(&Stack);

        if (mark[temp] == UNVISITED){
            mark[temp] = VISITED;
            printf("%d ",temp);
            for (j = 0; j < GRAPHSIZE; j++){
                if (g[j][temp] == 1){
                    push(&Stack,j);
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

void inputWGraph(int g[GRAPHSIZE][GRAPHSIZE]){
    printf("\n\tInputting Weighted Edges: \n");
    printf("\tHow many edges do you wish to add? ans = ");
    int numberOfEdges = 0;
    scanf("%d",&numberOfEdges);

    int i;
    int a,b,w;
    for (i = 0; i < numberOfEdges; i++){
        printf("\t%d.\n\tNode 1: ",i + 1);
        scanf("%d",&a);
        printf("\tNode 2: ");
        scanf("%d",&b);
        printf("\tWeight: ");
        scanf("%d",&w);

        g[a][b] = w;
        g[b][a] = w;
        printf("\tEdge (%d,%d) with weight %d added.\n\n",a,b,w);
    }
}


void traversePrim(int g[GRAPHSIZE][GRAPHSIZE]){
    int startingNode;
    printf("\n\tBreadth First Traversal:\n\tStarting Node: ");
    scanf("%d",&startingNode);

    int i,j;
    List *Queue = initQueue();
    VisitMark mark[GRAPHSIZE];
    for (i = 0; i < GRAPHSIZE; i++){
        mark[i] = UNVISITED;
    }

    int localMin;
    int closestNode;

    NQ(&Queue,startingNode);
    mark[startingNode] = VISITED;

    while (!isEmpty(&Queue)){
        int temp = DQ(&Queue);
        printf("%d ",temp);
        localMin = 9999;
        closestNode = temp;

        for (j = 0; j < GRAPHSIZE; j++){
            if (g[j][temp] > 0 && mark[j] == UNVISITED){
                if (g[j][temp] < localMin){
                    localMin = g[j][temp];
                    closestNode = j;
                }
            }
        }
        if (closestNode != temp){
            mark[closestNode] = VISITED;
            NQ(&Queue,closestNode);
        }

    }
}
