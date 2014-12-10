#include <stdio.h>
#include <stdlib.h>

int matrix[10][10], mst[10][10];

void prim(int nr_of_vertices, int source)
{
    int visited[nr_of_vertices], min_cost, all_visited=0, i, j, save1, save2;
    for (i=0;i<nr_of_vertices;i++)
        visited[i]=0;
    visited[source]=1;// source visited
    while(all_visited==0)
    {
        min_cost=9999;
        all_visited=1;
        for(i=0; i<nr_of_vertices && visited[i]==1; i++)
        {
            for(j=0; j<=nr_of_vertices && visited[j]==0; j++)
            {
                all_visited=0;
                if(matrix[i][j]!=0 && matrix[i][j]<min_cost)
                {
                    min_cost=matrix[i][j];
                    save1=i;
                    save2=j;
                }
            }
        }
        visited[save2]=1;
        mst[save1][save2]=matrix[save1][save2];
    }
    for(i=0; i<nr_of_vertices; i++)//print the minimum spanning tree
    {
        for(j=0; j<nr_of_vertices; j++)
            printf("%d\t", mst[i][j]);
        printf("\n");
    }

}

int main()
{
    int n, s, i, j;
    printf("Give the number of nodes: ");
    scanf("%d", &n);
    printf("Give the source node: ");
    scanf("%d", &s);
    printf("Give the adjancency matrix: \n");
    for(i=0; i<n; i++) //read the adjacency matrix
    {
        for(j=0; j<n; j++)
        {
            printf("matrix[%d][%d]= ", i, j);
            scanf("%d", &matrix[i][j]);
        }
        printf("\n");
    }
    prim(n, s);
    return 0;
}


