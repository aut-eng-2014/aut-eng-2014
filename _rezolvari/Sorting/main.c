#include "SortingAlgorithms.h"
#include "HelperFunctions.h"

int MAX = 101;
int MIN = 101;
int STEP = 100;

void doBubbleSort();
void doInsertionSort();
void doSelectionSort();
void doMergeSort();
void doQuickSort();
void changeConstants();
void removeFiles();

int main()
{
    printf("A - Bubble Sort\nB - Insertion Sort\nC - Selection Sort\nD - Merge Sort\nE - QuickSort\nF - All Sorting Algorithms\nX - Remove Files\nN - Change constants\nQ - Quit\n");

    char choice;
    while(1)
    {
        printf("Choice: ");
        choice = getch();
        printf("\n");
        switch(choice)
        {
        case 'A':
            doBubbleSort();
            break;

        case 'B':
            doInsertionSort();
            break;

        case 'C':
            doSelectionSort();
            break;

        case 'D':
            doMergeSort();
            break;

        case 'E':
            doQuickSort();
            break;

        case 'F':
            doBubbleSort();
            doInsertionSort();
            doSelectionSort();
            doMergeSort();
            doQuickSort();
            break;
        case 'X':
            removeFiles();
            break;

        case 'N':
            changeConstants();
            break;

        case 'Q':
            exit(0);
            break;

        default:
            printf("Bad Operation!\n");
            break;
        }
    }

    return 0;
}

void doBubbleSort()
{
    printf("Performing Bubble Sort with MIN = %d, MAX = %d and STEP = %d\n",MIN,MAX,STEP);
    FILE *fpBest,*fpWorst,*fpAverage;
    int currentCount;
    //! Bubble Sort
    fpBest = fopen("results/BubbleSort-Best.csv","w");
    fpAverage = fopen("results/BubbleSort-Average.csv","w");
    fpWorst = fopen("results/BubbleSort-Worst.csv","w");
    for(currentCount=MIN; currentCount<=MAX; currentCount+=STEP)
    {
        int *a;
        generateBest(&a,currentCount);
        bubbleSort(a,currentCount);
        fprintf(fpBest,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();


        generateAverage(&a,currentCount);
        bubbleSort(a,currentCount);
        fprintf(fpAverage,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();

        generateWorst(&a,currentCount);
        bubbleSort(a,currentCount);
        fprintf(fpWorst,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();
        printf("N: %d\n",currentCount);
    }
    fclose(fpBest);
    fclose(fpAverage);
    fclose(fpWorst);
}

void doInsertionSort()
{
    printf("Performing Insertion Sort with MIN = %d, MAX = %d and STEP = %d\n",MIN,MAX,STEP);
    FILE *fpBest,*fpWorst,*fpAverage;
    int currentCount;
    //! Insertion Sort
    fpBest = fopen("results/InsertionSort-Best.csv","w");
    fpAverage = fopen("results/InsertionSort-Average.csv","w");
    fpWorst = fopen("results/InsertionSort-Worst.csv","w");
    for(currentCount=MIN; currentCount<=MAX; currentCount+=STEP)
    {
        int *a;
        generateBest(&a,currentCount);
        insertionSort(a,currentCount);
        fprintf(fpBest,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();


        generateAverage(&a,currentCount);
        insertionSort(a,currentCount);
        fprintf(fpAverage,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();

        generateWorst(&a,currentCount);
        insertionSort(a,currentCount);
        fprintf(fpWorst,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();
        printf("N: %d\n",currentCount);
    }
    fclose(fpBest);
    fclose(fpAverage);
    fclose(fpWorst);
}

void doSelectionSort()
{
    printf("Performing Selection Sort with MIN = %d, MAX = %d and STEP = %d\n",MIN,MAX,STEP);
    FILE *fpBest,*fpWorst,*fpAverage;
    int currentCount;
    //! Insertion Sort
    fpBest = fopen("results/SelectionSort-Best.csv","w");
    fpAverage = fopen("results/SelectionSort-Average.csv","w");
    fpWorst = fopen("results/SelectionSort-Worst.csv","w");
    for(currentCount=MIN; currentCount<=MAX; currentCount+=STEP)
    {
        int *a;
        generateBest(&a,currentCount);
        selectionSort(a,currentCount);
        fprintf(fpBest,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();


        generateAverage(&a,currentCount);
        selectionSort(a,currentCount);
        fprintf(fpAverage,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();

        generateWorst(&a,currentCount);
        selectionSort(a,currentCount);
        fprintf(fpWorst,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();
        printf("N: %d\n",currentCount);
    }
    fclose(fpBest);
    fclose(fpAverage);
    fclose(fpWorst);
}

void doMergeSort()
{
    printf("Performing Merge Sort with MIN = %d, MAX = %d and STEP = %d\n",MIN,MAX,STEP);
    FILE *fpBest,*fpWorst,*fpAverage;
    int currentCount;
    //! Insertion Sort
    fpBest = fopen("results/MergeSort-Best.csv","w");
    fpAverage = fopen("results/MergeSort-Average.csv","w");
    fpWorst = fopen("results/MergeSort-Worst.csv","w");
    for(currentCount=MIN; currentCount<=MAX; currentCount+=STEP)
    {
        int *a, *b=NULL;
        resetArray(&b,currentCount);
        generateBest(&a,currentCount);
        mergeSortRecur(a,0, currentCount-1,b);
        fprintf(fpBest,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();

        resetArray(&b,currentCount);
        generateAverage(&a,currentCount);
        mergeSortRecur(a,0, currentCount-1,b);
        fprintf(fpAverage,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();

        resetArray(&b,currentCount);
        generateWorst(&a,currentCount);
        mergeSortRecur(a,0, currentCount-1,b);
        fprintf(fpWorst,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();
        printf("N: %d\n",currentCount);

        printToScreen(b,currentCount);
    }
    fclose(fpBest);
    fclose(fpAverage);
    fclose(fpWorst);
}

void doQuickSort()
{
    printf("Performing Quick Sort with MIN = %d, MAX = %d and STEP = %d\n",MIN,MAX,STEP);
    FILE *fpBest,*fpWorst,*fpAverage;
    int currentCount;
    //! Insertion Sort
    fpBest = fopen("results/QuickSort-Best.csv","w");
    fpAverage = fopen("results/QuickSort-Average.csv","w");
    fpWorst = fopen("results/QuickSort-Worst.csv","w");
    for(currentCount=MIN; currentCount<=MAX; currentCount+=STEP)
    {
        int *a;
        generateBest(&a,currentCount);
        quicksort(a,0, currentCount-1);
        fprintf(fpBest,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();


        generateAverage(&a,currentCount);
        quicksort(a,0, currentCount-1);
        fprintf(fpAverage,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();

        generateWorst(&a,currentCount);
        quicksort(a,0, currentCount-1);
        fprintf(fpWorst,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();
        printf("N: %d\n",currentCount);
    }
    fclose(fpBest);
    fclose(fpAverage);
    fclose(fpWorst);
}

void changeConstants()
{

    printf("New MIN: ");
    scanf("%d",&MIN);
    printf("\n");

    printf("New MAX: ");
    scanf("%d",&MAX);
    printf("\n");

    printf("New STEP: ");
    scanf("%d",&STEP);
    printf("\n");

}

void removeFiles()
{
    printf("Removing files...\n");
    remove("results/BubbleSort-Best.csv");
    remove("results/BubbleSort-Average.csv");
    remove("results/BubbleSort-Worst.csv");

    remove("results/InsertionSort-Best.csv");
    remove("results/InsertionSort-Average.csv");
    remove("results/InsertionSort-Worst.csv");

    remove("results/SelectionSort-Best.csv");
    remove("results/SelectionSort-Average.csv");
    remove("results/SelectionSort-Worst.csv");

    remove("results/MergeSort-Best.csv");
    remove("results/MergeSort-Average.csv");
    remove("results/MergeSort-Worst.csv");

    remove("results/QuickSort-Best.csv");
    remove("results/QuickSort-Average.csv");
    remove("results/QuickSort-Worst.csv");
    printf("Done!\n");
}
