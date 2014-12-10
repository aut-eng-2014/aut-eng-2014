#include <stdio.h>
#include <stdlib.h>

#define INF 99999;
int **g;

int min(int *dist, int *vis, int n)
{
    int i, minim=99999, poz;
    for(i=0; i<n; i++)
        if(vis[i]==0)
        {
            if(minim>dist[i])
            {
                minim=dist[i];
                poz=i;
            }
        }
    return poz;
}

void Dijkstra(int n, int source)//n =nr of nodes
{
    int *dist, *vis, i, j, v;
    dist=(int*)malloc(n*sizeof(int));
    vis=(int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        vis[i]=0;
        dist[i]=INF;
    }
    dist[source]=0;
    for(i=0; i<n; i++)
    {
        v=min(dist, vis, n);
        vis[v]=1;
        for(j=0; j<n; j++)
        {
            if(g[v][j]!=0)
                if(dist[j]>dist[v]+g[v][j])
                {
                    dist[j]=dist[v]+g[v][j];
                }
        }
    }
    for(i=0; i<n; i++)//print the distances
    {
        printf("dist[%d]=%d, ", i, dist[i]);
    }
}

int main()
{
    int n, s, i, j;
    printf("Give the number of nodes: ");
    scanf("%d", &n);
    g=(int**)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        *(g+i)=(int*)malloc(n*sizeof(int));
    }
    printf("Give the source node: ");
    scanf("%d", &s);
    printf("Give the adjancency matrix: \n");
    for(i=0; i<n; i++) //read the adjacency matrix
    {
        for(j=0; j<n; j++)
        {
            printf("matrix[%d][%d]= ", i, j);
            scanf("%d", &g[i][j]);
        }
        printf("\n");
    }
    Dijkstra(n, s);
    return 0;
}
