#include <stdio.h>
#include <stdlib.h>
#define INF 999

int minim_dist_index(int n, int *dist, int *visited)
{
    int i,minim=INF,index;
    for(i=0;i<n;i++)
    {
        if(visited[i]==0 && dist[i]<minim)
        {
            minim=dist[i];
            index=i;
        }
    }
    return index;
}
void disjkstra(int src, int n, int **a, int *dist)
{
    int visited[n];
    int aux,i,j,index;

    for(i=0;i<n;i++)
    {
        visited[i]=0;
        dist[i]=INF;
    }
    dist[src]=0;
    for(i=0;i<n;i++)
    {
        index=minim_dist_index(n,dist,visited);
        visited[index]=1;
        for(j=0;j<n;j++)
        {
            aux=dist[index]+a[index][j];
            if(visited[j]==0 && a[index][j] && dist[index]!=INF && aux<dist[j])
            {
                dist[j]=aux;
            }
        }
    }

}
int main()
{
    int n,j,i;
    int node,node1,node2;
    int rez=0;

    printf("Insert the number of nodes!\n n= ");
    scanf("%d",&n);
    printf("Insert the adjacency matrix!\n");
    int dist[n][n];
    int **a=(int**)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(i=0;i<n;i++)
    {
        disjkstra(i,n,a,&dist[i]);
    }

    printf("\n");
    printf("For ending the program press 1\n");
    printf("For finding the minim cost of a path between 2 nodes press 2\n");
    printf("For finding the minim cost of a path between a node and all the other nodes press 3\n");
    printf("For finding the minim cost of a path between all nodes press 4\n");

    while(rez!=5)
    {
        scanf("%d", &rez);
        if(rez==1)
        {
            break;
        }
        if(rez==2)
        {
            printf("Insert the two nodes!\n");
            printf("node 1= ");
            scanf("%d",&node1);
            printf("\nnode 2= ");
            scanf("%d",&node2);
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i==node1 && j==node2)
                    printf("%d --> %d : %d          ",i,j,dist[i][j]);
                }
            }
            printf("\n");
        }

        if(rez==3)
        {
            printf("Insert the value of the node!\n");
            printf("node= ");
            scanf("%d",&node);
            printf("\n");
            for(i=0;i<n;i++)
            {
                if(i==node)
                {
                    for(j=0;j<n;j++)
                    {
                        printf("%d --> %d : %d          ",i,j,dist[i][j]);
                    }
                }
            }
            printf("\n");
        }
        if(rez==4)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    printf("%d --> %d : %d          ",i,j,dist[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}
