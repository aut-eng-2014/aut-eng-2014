

int getMax(int *arr, int n)
{
    int mx = arr[0],i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort
void countSort(int *arr, int n, int exp)
{
    int *output = (int*)malloc(sizeof(int)*n); // output array
    int i, cont[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        cont[ (arr[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual position of
    // this digit in output[]
    for (i = 1; i < 10; i++)
        cont[i] += cont[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[cont[ (arr[i]/exp)%10 ] - 1] = arr[i];
        cont[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to curent digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using Radix Sort
void radixsort(int *arr, int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead of passing digit
    // number, exp is passed. exp is 10^i where i is current digit number
    int exp;
    for (exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
