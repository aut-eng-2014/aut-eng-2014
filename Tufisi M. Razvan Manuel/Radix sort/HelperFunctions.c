#include "HelperFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void allocateMem(int **x, int n){
    *x = (int*)malloc(sizeof(int)*n);
}

void generateWorst(int **x, int n)
{
    allocateMem(x,n);
    int i=0;
    for(i=n-1; i>=0; i--)
    {
        *(*x+i)=n-i;
    }
}

void generateBest(int **x, int n)
{
    allocateMem(x,n);
    int i=0;
    for(i=0; i<n; i++)
    {
        *(*x+i)=i;
    }
}

void generateAverage(int **x, int n)
{
    allocateMem(x,n);
    int i=0;
    for(i=0; i<n; i++)
        *(*x+i)=rand();
}

void printToScreen(int *x, int n)
{
    int i=0;
    for(i=0; i<n; i++)
        printf("%d ",x[i]);
}

void resetCounters()
{
    comparisons=0;
    assignments=0;
}

void resetArray(int **x, int n)
{
    if(*x==NULL)
        *x = (int*)malloc(sizeof(int)*n);
    memset(*x, 0, n * sizeof(int));
}

