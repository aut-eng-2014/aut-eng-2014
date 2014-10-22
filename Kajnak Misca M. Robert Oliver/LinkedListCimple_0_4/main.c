#include <stdio.h>
#include <stdlib.h>

#include "DLList.h"
///Simple program with lists. I hope I didn't miss any failsafes, I did try to test values at the limits as much as possible

int main()///it's simple and it's in C
{
    init(10,20);///I didn't comment this part since I considered it self explanatory; Reading the varialbes would have just slowed the progress, and this illustrates their usage anyway
    insrt(1,15);
    addLast(30);addLast(40);
    addFirst(5);addFirst(0);
    insrt(1,2);
    insrt(7,35);
    printAll();
    rmv(6);
    rmv(3);
    rmv(0);
    printAll();
    rmv(5);
    printAll();
    rmvS(0,2);
    printAll();
    //addLast(50);addLast(60);addLast(70);addLast(80);
    insrtS(30,4,50,60,70,80); ///demonstrates out of bounds address appended to the end
    printAll();
    rmvS(4,2);
    printAll();
    rmvS(3,5);
    printAll();
    insrtS(2,5,26,27,28,29,30);
    printAll();
    insrtS(0,2,0,4);
    printAll();
    printf("The 5. element is: ");printNode(8);printf("\n");
    printf("The first three elements are: ");printNodeS(0,3);
    printf("The last element is %d\n",getNodeValue(30));
    printf("The index of %d is %d\n",28,srchIndex(28));
    printf("The index of %d is %d\n",999,srchIndex(999));///demonstrates -1 index return for non-existing element
    printf("The length of the list is: %d\n",cnt());
    rmvVal(27);
    printAll();
    insrtS(3,5,99,88,77,66,4);
    srt();
    printf("After Sorting the array:\n");
    printAll();
    rmvValS(4);
    printf("After removing the 4s:\n");
    printAll();
    destruct();
    return 0;
}
