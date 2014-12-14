#include <stdio.h>
#include <stdlib.h>

void print(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}

void radixsort(int *a, int n)
{
    int i, maxim = a[0], exp = 1, index;
    int *sorted = (int*)malloc(n * sizeof(int));
    int *elem_count = (int*)malloc(10*sizeof(int));
    //find the greatest value from the array (because we need to know how many digits has)
    for (i = 1; i < n; i++)
    {
        if (a[i] > maxim)
            maxim = a[i];
    }
    //repeat until we traversed every digit from all numbers(take as reference "maxim")
    while (maxim / exp > 0)
    {
        for(i=0; i<10; i++) //initialize the vector which counts the no. of occurrences for every digit
        {
            elem_count[i]=0;
        }
        //Count how many occurences are for every digit
        for (i = 0; i < n; i++)
        {
            elem_count[(a[i] / exp) % 10]++;
        }
        //the final vector should have, at every position, the sum of all the previous positions + itself
        for (i = 1; i <10; i++)
        {
            elem_count[i] += elem_count[i - 1];
        }
        //Starting at the end of the list, get the index corresponding to the a[i]'s key, decrement it, and use it to place a[i] into array b.
        for (i = n - 1; i >= 0; i--)
        {
            index=(a[i] / exp) % 10;
            elem_count[index]=elem_count[index]-1;
            sorted[elem_count[index]] = a[i];
        }
        //Copy the partially sorted array to array a
        for (i = 0; i < n; i++)
        {
            a[i] = sorted[i];
        }
        //Multiply exp by 10 to get the next group of digits
        exp=exp*10;
        printf("\nPASS   : ");
        print(a, n);
    }
    free(elem_count);
    free(sorted);
}

int main()
{
    int i, n;
    printf("Enter total elements: ");
    scanf("%d", &n);
    int *arr =(int*) malloc(n * sizeof(int));

    printf("Enter %d Elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nARRAY  : ");
    print(arr, n);

    radixsort(arr, n);

    printf("\nSORTED : ");
    print(&arr[0], n);
    printf("\n");

    return 0;
}
