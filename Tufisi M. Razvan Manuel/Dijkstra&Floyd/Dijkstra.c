#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int minimum(int dist[],int vis[],int n )///a function that picks the minimum distance
{
    ///if the node is unvisited and retuns the index

    int min=INT_MAX, min_index,i;
    for(i=0; i<n; i++)
        if (vis[i]==0 && dist[i]<=min)
            min=dist[i], min_index=i;

    return min_index;

}

int main()
{
    int *vis,*dist,i,j,n,k;
    int **mat,startnod;

    FILE *pf;
    pf=fopen("adjmatrix.txt","r");

    fscanf(pf,"%d\n",&n);///We scan the number of vetices

    mat=(int**)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
        *(mat+i)=(int*)malloc(n*sizeof(int*));///we allocate memory for the adjacency matrix

    vis=(int*)malloc(n*sizeof(int));///we allocate memory for matrix visited and distance
    dist=(int*)malloc(n*sizeof(int));

    for(i=0; i<n; i++)
    {
        *(dist+i)=INT_MAX;///we fill the distance array with INT_MAX
    }
    for(i=0; i<n; i++)
    {
        *(vis+i)=0;///we fill the visited array with 0
    }


    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            fscanf(pf,"%d ",&mat[i][j]);///we read the matrix from the file

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ",mat[i][j]);///a print of the matrix
        printf("\n");
    }

    printf("Please input the start node:");
    scanf("%d",&startnod);///We pick-up a starting node
    dist[startnod]=0;

    for ( i= 0; i< n-1; i++)
    {
        ///k is always equal to startnod in first iteration
        k=minimum(&dist[i],&vis[i],n);///finds  index of nod with min cost

        vis[k]=1;///mark nod as visited

        ///update dist value of the adjacent node of the picked vertex.
        for (j = 0; j < n; j++)
            if (!vis[j] && mat[k][j] && dist[k] != INT_MAX)///if node unvisited and distance
                ///different from INT_max
                if(dist[k]+mat[k][j] < dist[j])///And if the cost is minimum
                    dist[j] = dist[k] + mat[k][j];///we update it with the sum of cost of previous and
    }                                                  ///curent node

    printf("Vertex   Distance from Source\n");
    for(i = 0; i < n; i++)
    {
        printf("%d \t\t %d\n", i, dist[i]);///We print the shortest path
    }
    return 0;

}

