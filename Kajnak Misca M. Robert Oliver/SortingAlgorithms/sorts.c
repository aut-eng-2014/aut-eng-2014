#include "sorts.h"

char isOrdered(int* a,int n)
{
    int i=1;
    char e=1;
    for (;e && (i<n);i++)
    {
        if (a[i-1]>a[i])
            e=0;
    }
    return e;
}

void bubbleSort(int * a,int n)
{
    int i,j;
    for (i=1;i<n-1;i++)
    {
        for (j=0;j<n-i;j++)
        {
            if (a[j]>a[j+1])
                swapp(&a[j],&a[j+1]);
        }
    }
}

void selectionSort(int * a, int n)
{
    int i,j,mini;
    for (i=0;i<n-1;i++)
    {
        mini=i;
        for (j=i;j<n;j++)
        {
            if (a[mini]>a[j])
                mini=j;
        }
        if (mini!=i)
            swapp(&a[mini],&a[i]);
    }
}

void insertSort(int* a,int n)
{
    int i,j;
    for (i=1;i<n;i++)
    {
        for (j=i;(j>0) && (a[j]<a[j-1]);j--)
            swapp(&a[j],&a[j-1]);
    }
}


void mrg(int *source,int low,int mid, int high, int* result);
void mergeSortRec(int* a,int l, int h,int *result);
int *mergeSort(int* a,int n)
{
    int *res=(int*)malloc(n*sizeof(int));
    mergeSortRec(a,0,n-1,res);
    return res;
}
void mergeSortRec(int* a,int l, int h,int *result)
{
    if (h>l)
    {
        int m=(l+h)/2;
        mergeSortRec(a,l,m,result);
        mergeSortRec(a,m+1,h,result);
        mrg(a,l,m,h,result);
    }
}
void mrg(int *a,int l,int m, int h, int* r)
{
    int i=l,j=m+1,k=0;
    while ((i<=m) && (j<=h))
    {
        if (a[i]<a[j])
        {
            r[k]=a[i];
            i++;
        }
        else
        {
            r[k]=a[j];
            j++;
        }
        k++;
    }

    if (i>m)
    {
        for (;j<=h;j++,k++)
        {
            r[k]=a[j];
        }
    }
    else
    {
        for (;i<=m;i++,k++)
        {
            r[k]=a[i];
        }
    }

    for (k=0;k<=h-l;k++)
    {
        a[k+l]=r[k];
    }
}

int choosePivot(int i,int j )
{
    return((i+j) /2);
}

void quickSort(int* a,int l, int h)
{
    if (l<h)
    {
        int pi=choosePivot(l,h);
        int pv=a[pi];
        if (pi!=l)
            swapp(&a[pi],&a[l]);
        /*else
            printf("unnecessary switch avoided\n");*/

        int i,j=h;
        for (i=l+1;i<=j;)
        {
            while ((a[i]<=pv) && (i<=j))
                i++;

            while ((a[j]>pv) && (j>=i))
                j--;

            if (i<j)
            {
                swapp(&a[i],&a[j]);
                i++;j--;
            }

        }
        if (j!=l)
            swapp(&a[j],&a[l]);
        /*else
            printf("unnecessary switch avoided\n");*/

        quickSort(a,l,j-1);
        quickSort(a,j+1,h);
    }
}

void radixSortLSD(int* a,int n)
{
    int base=8,logBase=3;///since I am using only a 10 long list, but i could just as well put 256 here
    int maxDigit=getMaxElementValue(a,n);
    stac *buckets[base];
    int i,j,k;
    for (i=0;i<base;i++)
        buckets[i]=NULL;

    for (i=1;i<maxDigit;i<<=logBase)
    {
        ///add to buckets
        for (j=0;j<n;j++)
        {
            stInsert(&buckets[(a[j]/i)%base],a[j]);
        }

        ///remove from buckets
        k=0;
        for (j=0;j<n;j++)
        {
            while (buckets[k]==NULL)
                k++;
            a[j]=stDequeue(&buckets[k]);
        }
    }
}
void radixSortBinRec(int* a,int l,int h,int mod);
void radixSortBin(int *a,int n)
{
    //int mod=1<<lg(getMaxElementValue(a,n),2);
    radixSortBinRec(a,-1,n,1<<(lg(getMaxElementValue(a,n),2)-1));
}

void radixSortBinRec(int* a,int l,int h,int mod)
{
    int lb=l,hb=h;///lb=lower bound, bound for 0s

    while (lb!=hb-1)
    {
        if (a[lb+1]&mod)
        {
            xorSwapp(&a[lb+1],&a[hb-1]);///it fits the mood, doesn't it?
            hb--;
        }
        else
        {
            lb++;
        }
    }

    if ((mod!=1))
    {
        if (l!=lb)
            radixSortBinRec(a,l,lb+1,mod>>1);
        if (hb!=h)
            radixSortBinRec(a,hb-1,h,mod>>1);
    }
}

