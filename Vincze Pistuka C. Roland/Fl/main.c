#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define inf 9999

int** allocmat (int sizegr)
{
    int **adj_mat;
    int i;
    adj_mat= (int**) malloc (sizeof (int*) * sizegr);
    for (i=0; i<sizegr; i++)
    {
        *(adj_mat+i)= (int*) malloc (sizeof (int) * sizegr);
    }
    return adj_mat;
}

int ** readmat (int** adj_mat, int sizegr)
{
    int i, j;
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

void Floyd (int **adj_mat, int sizegr, int **tablesequence)
{
    int i, j, k, value=0;
    for (i=0; i<sizegr; i++)
    {
        adj_mat[i][i]=0;
    }
    for (i=0; i<sizegr; i++)
    {
        for (j=0; j<sizegr; j++)
        {
            if (adj_mat[i][j]<adj_mat[j][i] && adj_mat[i][j]!=9999 && adj_mat[j][i]!=9999)
            {
                adj_mat[j][i]=adj_mat[i][j];
            }
            else
                if (adj_mat[j][i]<adj_mat[i][j] && adj_mat[i][j]!=9999 && adj_mat[j][i]!=9999)
                {
                    adj_mat[i][j]=adj_mat[j][i];
                }
                else
                {
                    if ((adj_mat[i][j]==9999) || (adj_mat[j][i]==9999))
                    {
                        adj_mat[i][j]=adj_mat[j][i]=9999;
                    }
                }
        }
    }
for (k=0; k<sizegr-1; k++)
{
    for (i=0; i<sizegr; i++)
    {
        for (j=0; j<sizegr; j++)
        {
            if (i!=j && i!=k && j!=k)
            {
                value= minim(adj_mat[i][j], adj_mat[i][k], adj_mat[k][j]);
                if (value!=adj_mat[i][j])
                {
                    tablesequence[i][j]=k;
                }
                adj_mat[i][j]=value;
            }
        }
    }
}
for (i=0; i<sizegr; i++)
{
    printf ("\n");
    for (j=0; j<sizegr; j++)
    {
        printf ("%d ", adj_mat[i][j]);
    }
}
for (i=0; i<sizegr; i++)
{
    printf ("\n");
    for (j=0; j<sizegr; j++)
    {
        printf ("%d ", tablesequence[i][j]);
    }
}
}

int main()
{
    int **(tabledist), **tablesequence;
    int sizegr, i, j;
    printf ("Please specify the number of vertices in the graph: ");
    scanf ("%d", &sizegr);
    tabledist= allocmat (sizegr);
    tabledist= readmat (tabledist ,sizegr);
    tablesequence= allocmat (sizegr);
    for (i=0; i<sizegr; i++)
    {
        for (j=0; j<sizegr; j++)
        {
            tablesequence[i][j]=j+1;
        }
    }
    Floyd (tabledist, sizegr, tablesequence);
    return 0;
}
