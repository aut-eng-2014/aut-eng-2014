#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(int *v, int n)
{
    int i;
    for (i = 0; i < n; i++)
        {
            printf("%d ", v[i]);
        }
}

void RadixSort(int *numbers, int TotalNumbers)
{

    int i;
    int maximum = numbers[0];
    int CurrentDigit = 1;
    const int base = 10; //it is used base 10

    int *semisorted = malloc(TotalNumbers * sizeof(int)); //a semisorted array
    int *bucket = calloc(base, sizeof(int)); //it will store the index of the sorted significant digits; initialized with 0

    //Find the maximum number in the array numbers
    //We will know how many digits to compare
    for (i = 1; i < TotalNumbers; i++)
    {
        if (numbers[i] > maximum)
            maximum = numbers[i];
    }

    //Loop until we traverse all the digits of the maximum number
    while (maximum / CurrentDigit > 0)
    {
        for(i=0;i<base;i++)
            bucket[i]=0;

        //Count the numbers that will go into each bucket considering their digit on the position CurrentDigit
        for (i = 0; i < TotalNumbers; i++)
        {
            bucket[(numbers[i] / CurrentDigit) % base]++;
        }

        //bucket[i] shows how many sorted elements by the position of CurrentDigit we have until position i in the array
        for (i = 1; i < base; i++)
        {
            bucket[i] += bucket[i - 1];
        }

        // Use the bucket to fill a "semiSorted" array
        for (i = TotalNumbers - 1; i >= 0; i--)
        {
            semisorted[--bucket[ (numbers[i] / CurrentDigit) % base ] ] = numbers[i];
        }

        //Copy array b to array numbeers
        for (i = 0; i < TotalNumbers; i++)
        {
        numbers[i] = semisorted[i];
        }

        CurrentDigit *= base; //Move to next significant digit
    }

    free(bucket);
    free(semisorted);
}

int main()
{
    int i, TotalNumbers;

    FILE*f;
    f=fopen("numbers.txt","r");

    if( f == NULL )
    {
        perror("Error while opening the file\n");
        exit(EXIT_FAILURE);
    }

    fscanf(f,"%d\n",&TotalNumbers);

    int *numbers = malloc(TotalNumbers * sizeof(int));

    for (i = 0; i < TotalNumbers; i++)
    {
        fscanf(f,"%d", numbers+i);
    }

    printf("\nThe unsorted numbers are  : ");
    print(numbers, TotalNumbers);

    RadixSort(numbers, TotalNumbers);

    printf("\n\nThe sorted numbers : ");
    print(&numbers[0], TotalNumbers);
    printf("\n");

    return 0;
}
