
#include <stdio.h>
#include <conio.h>
#include <process.h>
void main()
{
    int cost[10][10], path[10][10],n,p,v,row=1,column,i,j,min, dist[10];
    int index;
    printf("Enter number of nodes\n");
    scanf("%d", & n);
    printf("Enter cost matrix\n");
    for(i=1; i<=n;i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%d",  &cost[i][j]);
        }

    }

    printf("Enter the node to visit\n");
    scanf("%d", & v);
     printf("Enter the paths for the selected node\n");
    scanf("%d", & p);
     printf("Enter the path matrix\n");
     for(i=1; i<=p;i++)
     {
         for(j=1; i<=n;j++)
            {

             scanf("%d", &path[i][j]);
            }
     }

     for(i=1; i<=p;i++)
     {
         dist[i]=0;
         row=1;
         for(j=1; j<=n; j++)
         {
             if(row!=v)
             {
             column=path[i][j+1];
             dist[i]=dist[i]+cost[row][column];
            }
         row=column;
          }
     }

    min=dist[1];
    for(i=1; i<=p; i++)
    {
        if(dist[i]<=min)
        {
            min=dist[i];
            index=i;
        }
    }
    printf("the minimum distance is %d", min);
    printf("The minimum distance path");
    for(i=1; i<=n; i++)
    {
        if(path[index][i]!=0)
        printf("%d", path[index][i]);
    }
getch();
}



