#include "SortingAlgorithms.h"

/****************************************************
******************* Bubble Sort *********************
****************************************************/
int *bubbleSort(int *x, int n)
{
    int i,j=0;
    for(i=0; i<n; i++)
        for(j=0; j<n-i-1; j++)
        {
            comparisons++;
            if(x[j] > x[j+1])
            {
                int aux = x[j];
                x[j] = x[j+1];
                x[j+1]=aux;
                assignments+=3;
            }
        }
    return x;
}

/****************************************************
******************* Insertion Sort ******************
****************************************************/
int * insertionSort(int *x, int n)
{
    int i,j,tmp;
    for(i=1; i<n; i++)
    {
        j=i;
        comparisons+=2;
        while(j>0 && x[j-1]>x[j])
        {
            tmp=x[j];
            x[j]=x[j-1];
            x[j-1]=tmp;
            j--;
            assignments+=3;
        }
    }
    return x;
}

/****************************************************
******************* Selection Sort ******************
****************************************************/
int* selectionSort(int *x, int n)
{
    int i,j;
    int minI=0;

    for(i=0; i<n-1; i++)
    {
        minI=i;
        for(j=i+1; j<n; j++)
        {
            comparisons++;
            if(x[j] < x[minI])
            {
                minI = j;
            }

        }
        comparisons++;
        if(minI != i)
        {
            int aux=x[i];
            x[i]=x[minI];
            x[minI]=aux;
            assignments+=3;
        }
    }
    return x;
}

/****************************************************
******************* Merge Sort **********************
****************************************************/
void merge(int *a, int low, int high, int mid, int *endResult)
{
    int h,i,j,k;
    h=low;
    i=0;
    j=mid+1;
    k=low;

    while((h<=mid)&&(j<=high))
    {
        comparisons++;
        if(a[h]<=a[j])
        {
            endResult[i]=a[h];
            assignments++;
            h++;
        }
        else
        {
            endResult[i]=a[j];
            assignments++;
            j++;
        }
        i++;
    }

    if(h>mid)
    {
        for(k=j; k<=high; k++)
        {
            endResult[i]=a[k];
            i++;
            assignments++;
        }
    }
    else
    {
        for(k=h; k<=mid; k++)
        {
            endResult[i]=a[k];
            i++;
            assignments++;
        }
    }

    for(k=0; k<=high-low; k++)
    {
        a[k+low]=endResult[k];
        assignments++;
    }
}

void mergeSortRecur(int *a, int low, int high, int *endResult)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSortRecur(a,low,mid,endResult);
        mergeSortRecur(a,mid+1,high,endResult);
        merge(a,low,high,mid,endResult);
    }
}

/****************************************************
******************* Quick Sort **********************
****************************************************/
void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    assignments+=3;
}

int choose_pivot(int i,int j )
{
    return((i+j) /2);
}

void quicksort(int *x, int m, int n)
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap(&x[m],&x[k]);
        key = x[m];
        i = m+1;
        j = n;
        while(i <= j)
        {

            while((i <= n) && (x[i] <= key))
            {
                comparisons++;
                i++;
            }
            while((j >= m) && (x[j] > key))
            {
                comparisons++;
                j--;
            }
            if( i < j)
                swap(&x[i],&x[j]);
        }
        // swap two elements
        swap(&x[m],&x[j]);
        // recursively sort the lesser x
        quicksort(x,m,j-1);
        quicksort(x,j+1,n);
    }
}

/****************************************************
******************* Counting Sort *******************
****************************************************/
void countingSort(int *x, int n){
    int i;
    int *counter = (int*) malloc(sizeof(int) * INT_MAX);
    // If there would be a way to set starting values while allocating the memory, that would be great...
    for (i = 0; i < INT_MAX; i++){
        counter[i] = 0; // anyhow, this technically takes constant time... so this is O(1).
    }

    for (i = 0; i < n; i++){
        counter[x[i]]++;
        assignments++;
    }

    int index_of_x = 0;
    int j;
    for (i = 0; i < INT_MAX; i++){
        if (counter[i] != 0){
            for (j = 0; j < counter[i]; j++){
                x[index_of_x++] = i;
                assignments++;
            }
        }
    }
    if (index_of_x != n){
        //this should never happen
        exit(1);
    }
    // no comparisons WOOT!
}

/****************************************************
******************* Radix Sort **********************
****************************************************/

#define DIGITS 6

void radixSort(int *x, int n){
    return; //TODO finish this stuff someday...
  int counter[n][DIGITS];
  int i,j,k;
  for (i = 0; i < n; i++){
    for (j = 0; j < DIGITS; j++){
        counter[i][j] = 0;

    }
  }

  for (i = 0; i < n; i ++){
    while (x[i] > 0){
        int temp = 0;
        counter[i][temp++] = x[i] % 10;
        x[i] /= 10;
    }
  }

  int currentDigitNumber = DIGITS + 1;
  for (i = 1; i <= n; i++){
    currentDigitNumber--;
    int localBiggestDigitNumber = 0;
    int indexOfLocalBiggestDigitNumber = 0;
    for (j = i; j < n; j++){
        if (counter[j][currentDigitNumber] > currentDigitNumber){
            currentDigitNumber = counter[j][currentDigitNumber];
            indexOfLocalBiggestDigitNumber = j;
        }
    }

    for (j = currentDigitNumber; j ==0; j--){
        x[n-i-1] = x[n-i-1] * 10 + counter[indexOfLocalBiggestDigitNumber][localBiggestDigitNumber];
    }
  }
}

/****************************************************
******************* Bogo Sort ***********************
****************************************************/
void shuffle(int *x, int n){
    int *a = (int*) malloc(sizeof(int) * n);
    int i;
    for (i = 0; i < n; i++){
        a[i] = -1;
    }

    for (i = 0; i < n; i++){
        int temp = rand() % n;
        if (a[temp] == -1){
            temp = 0;
        }
        while (a[temp] == -1){
            temp++;
        }
        a[temp] = x[i];
        assignments++;
    }

    for(i = 0; i < n; i++){
        x[i] = a[i];
        assignments++;
    }
}

bool isSorted(int *x, int n){
    int i;
    for (i = 0; i < n-1; i++){
        comparisons++;
        if (x[i] > x[i+1]) return false;
    }
    return true;
}

void bogoSort(int *x, int n){
    srand(time(0));
    while (!isSorted(x,n)){
        shuffle(x,n);
    }
}

void resetCounters()
{
    comparisons=0;
    assignments=0;
}







