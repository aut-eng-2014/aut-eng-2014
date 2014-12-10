#include <stdio.h>
#include <stdlib.h>

int **g, **p;

void path(int i, int j)
{
    int k;
    k=p[i][j];
    if(k!=j)
    {
        path(i,k);
        printf("%d -> ", k);
        path(k,j);
    }
}

void Floyd(int n)
{
    int i, j, k, **dist;
    dist=(int**)malloc(n*sizeof(int));//memory allocation for distances
    for(i=0; i<n; i++)
    {
        *(dist+i)=(int*)malloc(n*sizeof(int));
    }
    p=(int**)malloc(n*sizeof(int));//memory allocation for Paths
    for(i=0; i<n; i++)
    {
        *(p+i)=(int*)malloc(n*sizeof(int));
    }
    for(i=0; i<n; i++)//initializing distances
        for(j=0; j<n; j++)
            dist[i][j]=g[i][j];
    for(i=0; i<n; i++)//initializing paths matrix
        for(j=0; j<n; j++)
        {
            if(i==j)
                p[i][j]=-1;
            else
                p[i][j]=j;
        }
    for (k=0; k<n; k++)//all nodes
        for(i=0; i<n; i++)//all lines
            for(j=0; j<n; j++)//all columns
                if (dist[i][k]+dist[k][j]<dist[i][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    p[i][j]=p[i][k];
                }
    for(i=0; i<n; i++)//print the all pairs shortest paths
    {
        for(j=0; j<n; j++)
            printf("%d\t", dist[i][j]);
        printf("\n");
    }
    for(i=0; i<n; i++)//print the intermediate vertices for the shortest paths
        for(j=i+1; j<n; j++)
        {
            printf("\nPath from %d -> %d: ", i, j);
            printf("%d -> ", i);
            path(i, j);
            printf("%d ", j);
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
    Floyd(n);
    getchar();
    return 0;
}
