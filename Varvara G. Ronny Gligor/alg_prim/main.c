#include <stdio.h>
#include <stdlib.h>
#define INF (1<<31)-1

int **prims(int **ingraph,int n)
{
    int i,j,lastNode=0,min=INF,nextNode,nodesLeft;
    nodesLeft=n-1;
    int *parent=(int*)malloc(sizeof(int)*n);
    int **outree=(int**)malloc(sizeof(int*)*n);
    for(i=0; i<n; i++)
    {
        outree[i]=(int*)malloc(sizeof(int)*n);
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            outree[i][j]=0;
        }
    char *visit=(char*)calloc(n,sizeof(char));
    int *key=(int*)malloc(sizeof(int)*n);
    key[0]=0;
    for(i=1; i<n; i++)
        key[i]=INF;
    visit[0]=1;
    while(nodesLeft>0)
    {
        min = INF;
        for(i=0; i<n; i++)
        {
            if(ingraph[lastNode][i] && !visit[i] && ingraph[lastNode][i]<key[i])
            {
                key[i]=ingraph[lastNode][i];
                parent[i]=lastNode;
            }
            if(!visit[i] && key[i]<min)
            {
                min=key[i];
                nextNode=i;
            }
        }
        visit[nextNode]=1;
        outree[parent[nextNode]][nextNode]=ingraph[parent[nextNode]][nextNode];
        lastNode=nextNode;
        nodesLeft--;
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(outree[i][j]!=0)
                printf("\nMuchia %d - %d, cost: %d",i,j,outree[i][j]);
    return 0;
}

int **read(int *n)
{
    FILE *f=fopen("date.in", "r");
    int **ingraph;
    if(f==NULL)
    {
        perror("msg:");
        exit(1);
    }
    int i, j;
    fscanf(f, "%d", n);
    ingraph=(int**)malloc(sizeof(int*)*(*n));
    for(i=0; i<*n; i++)
    {
        ingraph[i]=(int*)malloc(sizeof(int)*(*n));
    }
    for(i=0; i<*n; i++)
        for(j=0; j<*n; j++)
            fscanf(f, "%d", &ingraph[i][j]);
    return ingraph;
}

int main()
{
    int numberOfNodes;
    int **adjMatrix=read(&numberOfNodes);
    prims(adjMatrix,numberOfNodes);
    return 0;
}
