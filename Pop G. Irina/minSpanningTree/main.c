
//tema prim, sa citesc despre dijstra, floyd,kruskal
//Prim's algorithm with adjacent matrix
#include <stdio.h>
#include <stdlib.h>

int adjMatrix[100][100], numberOfNodes;

void Prim()
{
    int cost=0,visited[100],minimum=600,minPoz=0,i,startNode,j,nodesLeft;
    printf("Enter the number of nodes\n");
    scanf("\n%d", &numberOfNodes);
    nodesLeft=numberOfNodes;

    for (i=0;i<=numberOfNodes;i++)
        visited[i]=-1;
    printf("Enter the node you want to start from\n");
    scanf("%d",&startNode);
    visited[startNode]=0;
    printf("The order is : %d ",startNode);
    while (nodesLeft>0)
    {
        for (i=1;i<=numberOfNodes;i++)
            if (visited[i]!=-1)
                for (j=1;j<=numberOfNodes;j++)
                    if (adjMatrix[i][j]!=0 && adjMatrix[i][j]<minimum && visited[j]==-1)
                    {
                        minimum=adjMatrix[i][j];
                        minPoz=j;

                    }
        visited[minPoz]=minimum;

        printf("%d ",minPoz);
        nodesLeft--;
    }
    cost=0;
    for (i=1;i<=numberOfNodes;i++)
        cost+=visited[i];
    printf("The total cost is : %d\n",cost);
}

int main()
{
    printf("Here we go\n");
/*printf("\nEnter the adjacency matrix:\n");
    int adjMatrix[5][5] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };*/
    Prim();
    return 0;
}




