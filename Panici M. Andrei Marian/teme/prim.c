#include <stdio.h>
#include <stdlib.h>
#include "prim.h"

void prim_fct(){
struct muchie dunga[MAX],aux;
    int cost=0;
    int c,i,j,lung,n,k=0,x,y,m;
    FILE *f;
    f=fopen("in.txt","r");
    if(f==NULL)
    {
        perror("Error reading file !!!\n");
        exit(1);
    }
    c=1;
    fscanf(f,"%d",&m);//m=numarul de noduri
    while(!feof(f))
    {
        fscanf(f,"%d %d %d",&i,&j,&lung);
        dunga[c].a=i;
        dunga[c].b=j;
        dunga[c].pret=lung;
        c++;
    }
    n=c-1;

    for(i=1;i<=n-1;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(dunga[i].pret > dunga[j].pret)
            {
                aux=dunga[i];
                dunga[i]=dunga[j];
                dunga[j]=aux;
            }
        }
    }

    vizit[dunga[1].a]=1;
    vizit[dunga[1].b]=1;

    printf("<%d,%d> ",dunga[1].a,dunga[1].b);
    cost=dunga[1].pret;

    for(k=1;k<m-1;k++)
    {
        i=1;
        while(vizit[dunga[i].a]==vizit[dunga[i].b])
        {
            i++;
        }
        printf("<%d,%d> ",dunga[i].a,dunga[i].b);
        if(vizit[dunga[i].a]!=0)
        {
            vizit[dunga[i].b]=1;
        }
        else
        {
            vizit[dunga[i].a]=1;
        }
        cost=cost+dunga[i].pret;
    }
    printf("\nCost: %d",cost);}
