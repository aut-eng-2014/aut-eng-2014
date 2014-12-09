#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int dist[], int vis[], int V)
{
    int min = INT_MAX, min_index, i;
    for (i = 0; i < V; i++)
        if (vis[i] == 0 && dist[i] <= min)
            {
                min = dist[i];
                min_index = i;
            }
   return min_index;
}

void floydWarshall(int V, int graph[V][V])
{
    printf("\nchanges in path made by floyd warshall: \n");
    int i,j,k;
    for (k=0; k<V; k++) /*  for each vertex k, in order,
                            i try to put it between other two vertexex i and j
                            and check if the new distance (i through k and then to j)
                            is smaller than the original distance between i and j */
        for (i=0; i<V; i++)
            for (j=0; j<V; j++)
                if ( graph[i][k]!=0 && graph[k][j]!=0 && graph[i][j] > graph[i][k] + graph[k][j] )
                    {
                        graph[i][j]=graph[i][k]+graph[k][j];
                        /* print the change that has been made */
                        printf("%d goes through %d and then to %d (dist=%d)\n", i,k,j,graph[i][j]);
                    }

    printf("\nfloyd warshall, new distance matrix are\n");
    for (i=0; i<V; i++){
        for (j=0; j<V; j++)
                printf("%d ",graph[i][j]); printf("\n"); }

}

void dijkstra(int V, int graph[V][V], int src)
{
    int dist[V]; /* dist[i] holds the shortest distance from src to i */
    int vis[V];  /* vis[i] holds 0 if node i hasn't been visited yet, and 1 otherwise */

    /* init all distances to INF and all nodes as NOT visited */
    int i;
    for (i=0; i<V; i++)
        {
            dist[i] = INT_MAX;
            vis[i] = 0;
        }

    /* distance from src to src is 0 */
    dist[src] = 0;

    /* for each vertex, pick the "closest" neighbour, aka the vertex that takes the least cost to reach */
    for (i=0; i<V; i++)
     {
       int u = min(dist,vis,V);
       /* mark the vertex as visited */
       vis[u] = 1;

       /* update dist value of the adjacent vertices of the picked vertex u */
       int v;
       for (v = 0; v < V; v++)
        /*  update dist[v] only if it is not (yet) visited
            and the total cost of the path from src to v through u is smaller than the direct path from src to v */
         if (vis[v]==0 && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     /* print the distances */
        printf("dijkstra: shortest distance between \n");
        for (i = 0; i < V; i++)
            printf("%d and %d is %d\n", src,i, dist[i]);

}

int main()
{
    FILE *pf;
    pf=fopen("graph.txt", "r");
    if (pf!=NULL)
    {
        /* read graph from file */
        int V; /* number of vertices */
        fscanf(pf,"%d\n",&V);
        int graph[V][V];

        /* init graph with 0*/
        int i,j;
        for (i=0; i<V; i++)
             for (j=0; j<V; j++)
                graph[i][j]=0;

        /* get each edge and its weight from file */
        /* the file looks like this:
                6
                0 1 4
                0 5 2
                1 5 3
                ...
            where the first line is the nr of vertices
            and the next lines: vertex i, vertex j, edge between i and j */

        while (!feof(pf))
        {
            int cost;
            fscanf(pf,"%d %d %d\n",&i,&j,&cost);
            graph[i][j]=cost;
            graph[j][i]=cost;
        }

        fclose(pf);
        dijkstra(V,graph,0);
        floydWarshall(V,graph);
    }
    else
        printf("file not found / return");
    return 0;
}
