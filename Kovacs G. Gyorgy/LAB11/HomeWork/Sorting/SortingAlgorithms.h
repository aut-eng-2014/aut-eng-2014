#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <limits.h>

typedef enum{false,true}bool;

long comparisons;
long assignments;

void resetCounters();

int *bubbleSort(int *x, int n);

int *insertionSort(int *x, int n);

int *selectionSort(int *x, int n);

void mergeSortRecur(int *a, int low, int high, int *endResult);

void quicksort(int *x, int m, int n);

/*
    Added by Kovax
*/

void countingSort(int*,int);
void radixSort(int*,int);
void bogoSort(int*,int);
