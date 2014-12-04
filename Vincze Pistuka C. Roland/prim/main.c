#include <stdio.h>
#include <stdlib.h>
#define maxmat 10

int adj_matrix[maxmat][maxmat];

void readmatrix (int sizem)
{
    int i, j;
    printf("\nThe cost of traversing in matrixform (it must be smaller than 100): ");
    for (i=0; i<sizem; i++)
    {
        for (j=0; j<sizem; j++)
        {
            printf ("\nadj_matrix[%d][%d]=", i, j);
            scanf ("%d", &adj_matrix[i][j]);
            if (adj_matrix[i][j]>100)
            {
                printf ("Please give a valid cost smaller than 100");
                scanf ("%d", &adj_matrix[i][j]);
            }
        }
    }
}

void prim (int sizem)
{
    int i, j, num=0, minim=100;
    int visited[maxmat][maxmat];
    for (i=0; i<sizem; i++)
    {
        if (adj_matrix[i][i]!=0)
        {
            adj_matrix[i][i]=0;
        }
    }
    for (i=0; i<sizem; i++)
    {
        for (j=0; j<sizem; j++)
        {
            if (adj_matrix[i][j]>adj_matrix[j][i])
            {
                if (adj_matrix[j][i]==0)
                {
                    adj_matrix[j][i]=adj_matrix[i][j];
                }
                else
                {
                    adj_matrix[i][j]=adj_matrix[j][i];
                }
            }
            else
            {
                if (adj_matrix[i][j]<adj_matrix[j][i])
                {
                    if (adj_matrix[i][j]==0)
                    {
                        adj_matrix[i][j]=adj_matrix[j][i];
                    }
                    else
                    {
                        adj_matrix[j][i]=adj_matrix[i][j];
                    }
                }
            }
        }
    }
  for (i=0; i<maxmat; i++)
  {
      for (i=0; i<maxmat; i++)
      {
          visited[i][j]=0;
      }
  }
  for (i=0; i<sizem; i++)
  {
      for (j=0; j<sizem; j++)
      {
          if ((visited[i][j]==0) && (minim>adj_matrix[i][j]) && (adj_matrix[i][j]!=0))
          {
              printf ("\nOne edge that is part of the minimum spanning tree is: %d-%d", i, j);
              visited[i][j]=1;
              visited[j][i]=1;
              minim=adj_matrix[i][j];
          }
      }
    if (i==num)
    {
        i=0;
        num++;
        minim=100;
    }
  }
}

int main ()
{
    printf ("Please specify the number of vertices in the graph: ");
    int sizeofmat;
    scanf ("%d", &sizeofmat);
    readmatrix (sizeofmat);
    prim (sizeofmat);
    return 0;
}
