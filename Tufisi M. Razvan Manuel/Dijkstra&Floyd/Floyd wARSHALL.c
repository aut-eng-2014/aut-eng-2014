#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define INF 9999

int main()
{
    int i,j,n,k;
    int **mat,**dist;

    FILE *pf;
    pf=fopen("adjmatrix.txt","r");

    fscanf(pf,"%d\n",&n);///We scan the number of vetices

    mat=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++)
        *(mat+i)=(int*)malloc(n*sizeof(int));///we allocate memory for the adjacency matrix

    dist=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++)
        *(dist+i)=(int*)malloc(n*sizeof(int));///we allocate memory for the distance matrix

    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            fscanf(pf,"%d ",&mat[i][j]);///we read the matrix from the file
        }

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ",mat[i][j]);///a print of the matrix
        printf("\n");
    }


    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            dist[i][j] = mat[i][j];///we initialize the solution matrix as the input one


    for (k=0; k<n; k++) ///chose every node as a intermediate vertix
    {
        /// pick all vertices as source one by one
        for (i=0; i<n; i++)
        {
            /// pick all vertices as destination for the
            /// above picked source
            for (j=0; j<n; j++)
            {
                /// if vertex k is on the shortest path from
                /// i to j, then update the value of dist[i][j]
                if (dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }

    printf ("Result matrix for shortest distances:\n");
    for (i=0; i<n; i++)
    {
        for ( j=0; j<n; j++)
        {
            if (dist[i][j] == 9999)
                printf("%7s", "INF");
            else
                printf ("%7d", dist[i][j]);
        }
        printf("\n");
    }
    return 0;
}
