#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "main.h"

int main()
{
    char c,op;

    do
    {
        printf("\t\nHello!Welcome to the command menu!\n    Please chose one of the following options:\n");
        printf("\n1.Press D for delete\n");
        printf("\n2.Press F for find\n");
        printf("\n3.Press S to show\n");
        printf("\n4.Press I to insert\n");
        printf("\n5.Press Q to quit\n");
        c=getche();
        op=toupper(putch(c));
           nodeT *root=NULL;
           int n;

        switch(op)
        {
        case 'D':
            printf("Please input the node you want to delete:");
            scanf("%d",&n);
            deleteNode(root,n);
            break;
        case 'F':
            printf("Please input the node you want to find:");
            scanf("%d",&n);
            searchNode(root,n);
            break;
        case 'S':
            inorder(root);
            break;
        case 'I':
            printf("Please input the node you want to insert:");
            scanf("%d",&n);
            insertNode(root,n);
            break;
        case 'Q':
            exit(1);
        default:
            printf("\nIncorrect!!!!Please chose one of the commands from the menu!\n\n");
        }
    }
    while(c!='q'||c!='Q');

    return 0;
}
