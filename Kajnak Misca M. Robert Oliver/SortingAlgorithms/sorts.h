#ifndef SORTS_H_INCLUDED
#define SORTS_H_INCLUDED

#include "auxFunctions.h"
#include "stack.h"

///params: the array and it's length
char isOrdered(int*,int);

void bubbleSort(int *,int);
void selectionSort(int *,int);
void insertSort(int*,int);
int* mergeSort(int*,int);
void quickSort(int*,int low ,int high);

void radixSortLSD(int*,int);
void radixSortBin(int*,int);

#endif // SORTS_H_INCLUDED
