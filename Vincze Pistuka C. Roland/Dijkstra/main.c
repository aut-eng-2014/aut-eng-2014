#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define inf INT_MAX

int** readmat (int sizegr)
{
    int **adj_mat;
    int i, j;
    adj_mat= (int**) malloc (sizeof (int*) * sizegr);
    for (i=0; i<sizegr; i++)
    {
        *(adj_mat+i)= (int*) malloc (sizeof (int) * sizegr);
    }
    for (i=0; i<sizegr; i++)
    {
        for (j=0; j<sizegr; j++)
        {
            printf ("\nadj_mat[%d][%d]=", i, j);
            scanf ("%d", *(adj_mat+i)+j);
        }
    }
    return adj_mat;
}

int minim (int minval, int precval, int newval)
{
    int sum=precval+newval;
    if (minval>sum)
    {
        return sum;
    }
    else
    {
        return minval;
    }
}

void Djikstra (int **adj_mat, int *visited, int *minvalues, int sizegr)
{
    int initval, minimum=inf, i, j, col;
    printf ("\nPlease specify the vertex from which to start the algorithm: ");
    scanf ("%d", &initval);
    minvalues[initval]=0;
    for (i=0; i<sizegr; i++)
    {
        adj_mat[i][i]=0;
    }
    for (i=0; i<sizegr; i++)
    {
        for (j=0; j<sizegr; j++)
        {
            if (adj_mat[i][j]<adj_mat[j][i])
            {
                adj_mat[j][i]=adj_mat[i][j];
            }
            else
                if (adj_mat[j][i]<adj_mat[i][j])
                {
                    adj_mat[i][j]=adj_mat[j][i];
                }
                else
                {
                    if ((adj_mat[i][j]==0) || (adj_mat[j][i]==0))
                    {
                        adj_mat[i][j]=adj_mat[j][i]=0;
                    }
                }
        }
    }
    for (i=0; i<sizegr; i++)
    {
        for (j=0; j<sizegr; j++)
        {
            if ((adj_mat[i][j]!=0) && (visited[j]==0))
            {
                minvalues[j]=minim (minvalues[j], minvalues[i], adj_mat[i][j]);
            }
        }
        for (j=0; j<sizegr; j++)
        {
            if ((visited[j]==0) && (minvalues[j]<minimum))
            {
                minimum=minvalues[j];
                col=j;
            }
        }
    visited[col]=1;
    printf ("\nThe dist of element %d is: %d", col, minimum);
    minimum=inf;
    }
}

int main()
{
    int **(adj_mat);
    int *visited, *minvalues;
    int sizegr, i;
    printf ("Please specify the number of vertices in the graph: ");
    scanf ("%d", &sizegr);
    adj_mat=readmat (sizegr);
    visited=(int*) malloc (sizeof(int) * sizegr);
    minvalues=(int*) malloc (sizeof(int) * sizegr);
    for (i=0; i<sizegr; i++)
    {
        *(minvalues+i)=inf;
    }
    for (i=0; i<sizegr; i++)
    {
        *(visited+i)=0;
    }
    Djikstra(adj_mat, visited, minvalues, sizegr);
    return 0;
}
