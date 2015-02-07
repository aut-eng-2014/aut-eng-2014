#include <stdio.h>
#include <stdlib.h>

void radixSort(int A[], int n)
{
    int bucket[10][n],app[10];
    /* bucket contains the numbers from the vector grouped by their selected digit. at first step, by their last digit */

    /* determine the max number in the vector */
    int maxn=A[0];
    int i;
    for(i=0; i<n; i++)
        if(A[i]>maxn)
            maxn=A[i];

    /* determine the max number's number of digits */
    int sizen=0;
    while(maxn>0)
        {
            sizen++;
            maxn=maxn/10;
        }

    int div=1; /* start from the last digit */
    int count;
    for(count=0; count<sizen; count++) /* if n number of digits, iterate the loop n times */
        {
            for(i=0 ; i<10 ; i++)
                app[i] = 0; /* none of the digits have "appeared" yet */
                            /* n numbers with the same digit at the desired position, results in app[digit]=n */

            for(i=0; i<n; i++)
            {
                int digit=(A[i]/div)%10;
                bucket[digit][app[digit]++]=A[i]; /* group the numbers in the buckets */
            }

            /* send them back to the original vector A */
            i=0;
            int j,k;
            for(k=0; k<10; k++)
                for(j=0 ; j<app[k] ; j++)
                    A[i++] = bucket[k][j];

            /* go to next digit */
            div*=10;
        }

}


int main()
{
    int A[] = {12012,21312,43,545,90,7,242,43243};
    int n = sizeof(A)/sizeof(A[0]);
    radixSort(A,n);
    int i;
    for (i=0; i<n; i++)
        printf("%d ", A[i]);
    return 0;
}
