#include "sorts.h"

int main()
{
    int *x=NULL,*a=NULL;///array to be sorted || x tsa annoown
    int n=10;
    x=genRandArr(n,0,300);
    a=copyArray(x,n);

    printf("The original array:\n");
    dispArray(x,n);

    printf("\nBubble sorted:\n");
    int *bs=copyArray(a,n);
    bubbleSort(bs,n);
    dispArray(bs,n);
    //free(bs);

    printf("\nSeleciton Sorted:\n");
    int *ss=copyArray(a,n);
    selectionSort(ss,n);
    dispArray(ss,n);
    //free(ss);

    printf("\nInsertion Sorted:\n");
    int *is=copyArray(a,n);
    insertSort(is,n);
    dispArray(is,n);
    //free(is);

    printf("\nMerge Sorted:\n");
    int *ms=copyArray(a,n);
    ms=mergeSort(ms,n);
    dispArray(ms,n);
    //free(is);

    printf("\nQuick Sorted:\n");
    int *qs=copyArray(a,n);
    quickSort(qs,0,n-1);
    dispArray(qs,n);
    //free(qs)

    /*printf("\nFor an larger array, quicksort result:\n");
    x=genRandArr(1000000,0,100000);
    quickSort(x,0,999999);
    printf("It is%s%s",(isOrdered(x,n)?" ":" not "),"ordered\n");*/

    printf("\nRadix Sorted:\n");
    int *rs=copyArray(a,n);
    radixSortLSD(rs,n);
    dispArray(rs,n);
    //free(rs)

    printf("\nIn-place MSD radix Sorted:\n");
    int *rsb=copyArray(a,n);
    radixSortBin(rsb,n);
    dispArray(rsb,n);
    //free(rsb)
    return 0;
}

