#include "auxFunctions.h"

int lg(int n, int base)
{
    int i;
    for (i=0;n>0;i++)
        n/=base;
    return i;
}

int getMaxElementValue(int* a,int n)
{
    int i=0;
    int m=INT_MIN;

    for (;i<n;i++)
        if (a[i]>m)
            m=a[i];
    return m;
}

int getMaxElementIndex(int* a,int n)
{
    int i=0;
    int m=0;

    for (;i<n;i++)
        if (a[i]>a[m])
            m=i;
    return m;
}

void getMaxElement(int * a,int n,int* index,int *value)
{
    int i=0;
    int mv=INT_MIN;
    int mi=0;

    for (;i<n;i++)
        if (a[i]>mv)
        {
            mv=a[i];
            mi=i;
        }
    *index=mi;
    *value=mv;
}

void swapp(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void xorSwapp(int *x,int *y)
{
    if (x!=y)
    {
        *x^=*y;
        *y^=*x;
        *x^=*y;
    }
}

int * genRandArr(int length,int l1,int l2)///limit 1 and 2
{
    if (l1>l2)
        swapp(&l1,&l2);
    if (l1==l2)
    {
        int *x=(int*)malloc(length*sizeof(int));
        int i=0;
        for (;i<length;i++)
            x[i]=l1;
        return x;
    }

    srand(time(NULL));
    int *x=(int*)malloc(length*sizeof(int));
    int i=0;
    for (;i<length;i++)
    {
        x[i]=l1+rand()%(l2-l1);
    }
    return x;
}

int * copyArray(int *a, int n)
{
    int *x=(int*) malloc(n*(sizeof(int)));
    int i=0;
    for (;i<n;i++)
    {
        x[i]=a[i];
    }
    return x;
}


void dispArray(int* a,int n)
{
    if (a==NULL)
        return;

    int i=0;
    n--;
    for (;i<n;i++)
        printf("%d  |  ",a[i]);
    printf("%d\n",a[n]);
}
