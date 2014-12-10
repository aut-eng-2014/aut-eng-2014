#include <stdio.h>
#include <stdlib.h>
#define INF 65000

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
            if(ingraph[lastNode][i] && !visit[i] && ingraph[lastNode][i]+key[lastNode]<key[i])
            {
                key[i]=ingraph[lastNode][i]+key[lastNode];
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
        outree[nextNode][parent[nextNode]]=ingraph[nextNode][parent[nextNode]];
        lastNode=nextNode;
        nodesLeft--;
    }
    printf("Costurile muchiilor sunt: ");
    for(i=0;i<n;i++) printf("%d ",key[i]);
    printf("\n");

    for(i=0; i<n; i++)
        for(j=i; j<n; j++)
            if(outree[i][j]!=0)
            printf("\nMuchia %d - %d, cost: %d",i,j,outree[i][j]);

        return outree;
    return 0;
}

int cost(int **inmat,int n)
{
    int i,j,price=0;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            price+=inmat[i][j];
    return price/2;
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
    //printf("Here we go\n");
    int numberOfNodes;
    int **adjMatrix=read(&numberOfNodes);
    int **returtree,i,j;
    returtree=prims(adjMatrix,numberOfNodes);
    printf("\n\nMatricea de adiacenta a grafului nou construit este: \n");
    for(i=0; i<numberOfNodes; i++)
    {
        for(j=0; j<numberOfNodes; j++)
            printf("%d ", returtree[i][j]);
        printf("\n");
    }
    //to do: FREE MEMORY!!!
    return 0;
}
