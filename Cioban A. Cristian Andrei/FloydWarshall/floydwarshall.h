
#include <stdio.h>
#include <stdlib.h>

void floydWarshall (int n, int **graph)
{
    /*
        n = nr of vertices
        graph = cost matrix
    */

    /*dist matrix is the output matrix*/
    int **dist, i, j, k;

    /* allocate memory for the output matrix*/
    dist = (int **)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++){
        dist[i] = (int *)malloc(sizeof(int)*n);
    }

    /* Initialize the solution matrix same as input graph matrix.  */
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];


    for (k = 0; k < n; k++)
    {
        /*pick all nodes one by one*/
        for (i = 0; i < n; i++)
        {
            /* go through all nodes*/
            for (j = 0; j < n; j++)
            {
                /*if k is on shortest path from i to j
                then update dist*/
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    //prints the shortest distance matrix

    printf("\n\nthe shortest distance matrix is:\n");
    for (i = 0; i < n; i++)
        {for (j = 0; j < n; j++)
            printf("%d ",dist[i][j]);
            printf("\n");
        }
}







