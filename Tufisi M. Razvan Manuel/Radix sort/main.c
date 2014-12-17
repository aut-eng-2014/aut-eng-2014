#include <stdio.h>
#include <stdlib.h>
#include "HelperFunctions.h"

int MAX = 10000;
int MIN = 100;
int STEP = 100;

void radixsort(int n,int v[])
{
    int max,i,exp,*newv,count[10];///variable declaration

    newv=(int*)malloc(n*sizeof(n));///we allocate memory for the new array contained the sorted elements

    max=v[0];
    for(i=1; i<n; i++)
    {
        if(max<v[i])
            max=v[i];///we get the maximum value in the array
        assignments++;
        comparisons++;
    }

    for(exp=1; max/exp>0; exp=exp*10)///we need to get every digit of all elements from the list
    {
        ///and for that we repeat the procedure for the maximum number of digits
        for(i=0; i<10; i++)
        {
            count[i]=0;///we initialize with 0's all elements in the count array
            assignments++;
        }

        for(i=0; i<n; i++)
        {
            count[(v[i]/exp)%10]++;
            assignments++;
        }///we store count of occurences in count(ex:if last digit is 1 for 3 elements
        for(i=1; i<10; i++)                                                         ///count[3]=3)
        {
            count[i]=count[i]+count[i-1];
            assignments++;
        }///we change count[i] so that it may contain the actual position of the digit
        for(i=n-1; i>=0; i--)///we build the new sorted array
        {
            newv[count[(v[i]/exp)%10]-1]=v[i];
            count[(v[i]/exp)%10]--;
            assignments++;
        }
        for(i=0; i<n; i++)
        {
            v[i]=newv[i];///we copy the new array into the old one
            assignments++;
        }
        assignments++;
    }

}

void doRadixSort()
{
    printf("Performing Merge Sort with MIN = %d, MAX = %d and STEP = %d\n",MIN,MAX,STEP);
    FILE *fpBest,*fpWorst,*fpAverage;
    int currentCount;
    //! Radix Sort
    fpBest = fopen("results/MergeSort-Best.csv","w");
    fpAverage = fopen("results/MergeSort-Average.csv","w");
    fpWorst = fopen("results/MergeSort-Worst.csv","w");
    for(currentCount=MIN; currentCount<=MAX; currentCount+=STEP)
    {
        int *a;
        generateBest(&a,currentCount);
        radixsort(currentCount-1,a);
        fprintf(fpBest,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();


        generateAverage(&a,currentCount);
        radixsort( currentCount-1,a);
        fprintf(fpAverage,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();

        generateWorst(&a,currentCount);
        radixsort(currentCount-1,a);
        fprintf(fpWorst,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();
        printf("N: %d\n",currentCount);


    }
    fclose(fpBest);
    fclose(fpAverage);
    fclose(fpWorst);
}

int main()
{
    int n,*v,i;
    FILE *pf;
    pf=fopen("datain.txt","r");

    fscanf(pf,"%d\n",&n);
    v=(int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
        fscanf(pf,"%d",(v+i));

    radixsort(n,v);
    doRadixSort();

    for(i=0; i<n; i++)
        printf("%d  ",*(v+i));
    return 0;
}
