#include <stdio.h>
#include <stdlib.h>
#include "radix.h"

int main()
{
    FILE *f;
    f = fopen("array.txt","r");
    if(f != NULL) {

        int n,i;
        fscanf(f,"%d\n",&n);
        int *arr = (int *)malloc(sizeof(int)*n);
        for( i = 0; i < n; i++) {
            fscanf(f,"%d ",&arr[i]);
        }
        printf("array before sort:\n");
        for( i =0; i < n;i++) {
            printf("%d ",arr[i]);
        }
        printf("\narray after sort:\n");
        radixsort(arr,n);
        for( i =0; i < n;i++) {
            printf("%d ",arr[i]);
        }
    }
    return 0;
}
