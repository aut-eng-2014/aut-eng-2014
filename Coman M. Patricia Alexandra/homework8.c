#include <stdio.h>
#include <stdlib.h>
#define nmax 100
#define infinit 2000

float distante[nmax];
float cost[nmax][nmax];
int tata[nmax];
int s[nmax];


int  citire_graf()
{
    int i, j,n;
    FILE *f;
    f=fopen("D:\facultate\PATI an2\DSA\dsa lab\dsa\deikstra","r");
    fscanf(f,"%d",&n);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        {
            fflush(stdin);
            fscanf(f,"%f",&(cost[i][j]));
        }
    return n;
}

void dijkstar (int n,int sursa)
{
    int i,j,pas,k,min;
    // initializari
    for (i=1;i<=n;i++)
    {
       s[i]=0;
       distante[i]=cost[sursa][i];
        if (distante[i]<infinit)
                tata[i]=sursa;
        else
                tata[i]=0;
    }
    s[sursa]=1;
    tata[sursa]=0;
    distante[sursa]=0;
    for (pas=1;pas<=n-1;pas++)
    {
        // minimul distante
        min=infinit;
        int control=0;
        while (control==0)
        {    for (j=1;j<=n;j++)
                if (distante[j]<min && s[j]==0)
                    {
                    min=distante[j];
                    control=1;
                    k=j;
                    }
        }
       if (min==infinit) return;
       s[k]=1;
       for (j=1;j<=n;j++)
            if (s[j]==0 && distante[k]+cost[k][j]<distante[j])
            {
              distante[j]=distante[k]+cost[k][j];
              tata[j]=k;

            }

    }
}

void path(int d)
{
    if (d!=0)
    {
            path(tata[d]);
            printf("<--- %d", d);
    }
    return;
}

int main()
{
    int n,i,j,sursa;
    printf("oleeeee!!! it works \n");
    scanf( "%d", &n);
    n=citire_graf();
    for (i=1;i<=n;i++)
        {
            printf("\n");
            for (j=1;j<=n;j++)
            {
                printf("%f  ",(cost[i][j]));
            }
        }
    sursa=1;
    dijkstar(n,sursa);
    printf("\n");
    path(5);
    getch();
    return 0;
}
