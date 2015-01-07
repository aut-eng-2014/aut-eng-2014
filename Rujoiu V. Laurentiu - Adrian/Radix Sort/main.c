#include <stdio.h>

int min = 0, count = 0, array[100] = {0}, array1[100] = {0};

int *radixSort(int *x, int n)
{
    int i, k, temp, j, t;
    for (k = 0; k < 3; k++)
    {
        for (i = 0; i < count; i++)
        {
            min = x[i] % 10;        /**To find minimum lsd **/
            t = i;
            for (j = i + 1; j < count; j++)
            {
                if (min > (x[j] % 10))
                {
                    min = x[j] % 10;
                    t = j;
                }
            }
            temp = array1[t];
            array1[t] = array1[i];
            array1[i] = temp;
            temp = x[t];
            x[t] = x[i];
            x[i] = temp;

        }
        for (j = 0; j < count; j++)        /*to find MSB */
            x[j] = x[j] / 10;
    }
}


void main()
{
    int k, i, j, temp, t, n;

    printf("Enter size of array :");
    scanf("%d", &count);
    printf("Enter elements into array :");
    for (i = 0; i < count; i++)
    {
        scanf("%d", &array[i]);
        array1[i] = array[i];
    }

    radixSort(array, count);

    printf("Sorted Array (radix sort) : ");
    for (i = 0; i < count; i++)
        printf("%d ", array1[i]);
}
