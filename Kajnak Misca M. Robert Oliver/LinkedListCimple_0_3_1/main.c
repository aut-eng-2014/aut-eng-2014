#include <stdio.h>
#include <stdlib.h>

#include "DLList.h"

int main()///it's simple and it's in C
{
    printf("Hello world!\n");
    init(10,20);
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
    insrtS(30,4,50,60,70,80);
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
    return 0;
}
