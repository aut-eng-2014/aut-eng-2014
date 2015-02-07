#ifndef AUXFUNTIONS_H_INCLUDED
#define AUXFUNTIONS_H_INCLUDED

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int lg(int n, int base);

int getMaxElementIndex(int*,int);
int getMaxElementValue(int*,int);
void getMaxElement(int * Array,int length,int* index,int *value);

void swapp(int*,int*);
void xorSwapp(int*,int*);
int * genRandArr(int length,int minVal,int maxVal);
int * copyArray(int *,int);

void dispArray(int*,int);

#endif // AUXFUNTIONS_H_INCLUDED
