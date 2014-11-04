#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

///It works correctly in debugger for until the first "show", but not in build and run. I narrowed it down to the memory allocation using the commented lines
///In the delete the debugger stops several times at  free(np), but doesn't give any errors. I have no ideea why this is happening. Please give me at least a hint

int main()
{
    node* root=NULL;
    int n;
    char c;

    //root=insertNode(root,10);root=insertNode(root,11);root=insertNode(root,12);root=insertNode(root,20);root=insertNode(root,30);root=insertNode(root,14);

    FILE* f;
    f=fopen("input.txt","r");
    if (f==NULL)
        return 0x404;
    while ((c!=EOF) && (c!='q'))
    {
        fscanf(f,"%c",&c);
        switch (c)
        {
        case ('i'):
            fscanf(f,"%d",&n);
            root=insertNode(root,n);
            break;
        case ('d'):
            fscanf(f,"%d",&n);
            deleteNode(root,n);
            break;
        case ('f'):
            fscanf(f,"%d",&n);
            findNode(root,n);
            break;
        case ('s'):
            preorder(root);
            printf("\n");
            break;
        case ('q'):
            return 0;
            break;
        }
    }
    return 0;
}
