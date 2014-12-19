#include<stdio.h>
#define V 4
#define INF 99999
void PrintTheSolution(int distance[][V]);


void Floyd (int graph[][V])
{

    int distance[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            distance[i][j] = graph[i][j];
    for (k = 0; k < V; k++)
    {
        // Pick vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick vertices as destination for the source
            for (j = 0; j < V; j++)
            {

                if (distance[i][k] + distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }

    PrintTheSolution(distance);
}
void PrintTheSolution(int distance[][V])
{ int i, j;
    printf ("The shortest distances between every pair of vertices \n");
    for ( i = 0; i < V; i++)
    {
        for ( j = 0; j < V; j++)
        {
            if (distance[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", distance[i][j]);
        }
        printf("\n");
    }
}

int main()
{int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    Floyd(graph);
    return 0;
}
