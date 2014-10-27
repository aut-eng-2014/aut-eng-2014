#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() ///正しい,普通の木でわありません - NGNL reference. 'Cause you always need some reference
{           ///google translate this if you want a laugh, but I actually (am fairly positive, that) wrote it correctly, saying "Actually, this is not an ordinary tree"
            ///all hail google translate!
    f=fopen("function.txt","r");
    if (f==NULL)
    {
        printf("File Read error");
        return codeGen(0x404);///the pun is intended
    }

    node * tree=createBinaryTree();
    preorder(tree);
    printf("\n");
    inorder(tree);
    printf("\n");
    postorder(tree);
    printf("\n");///now say pre-in-post 5 times quickly

    lstInit();
    createListFromTree(tree);
    printlst();///this demonstrates that the tree is intact, it has not been chopped down or otherwise "mutilated"
    printf("\n");///problem 6.5 didn't say it had to be converted back, only that "such a way that you can reconstruct the tree"
                ///It can obvously be reconstructed, just replace the fscanf w/ p->val and p->type from the createBinaryTree
                ///If you deem it necessary I will ad that aswell

    printf("\nAfter recreating tree:\n");
    initCreateTreeFromList();
    node* tree2=createTreeFromList(first);
    preorder(tree2);
    printf("\n");

    printf("\nThe result of the calculation: ");
    printf("%.2f\n",calculate());

    return 0;
}
