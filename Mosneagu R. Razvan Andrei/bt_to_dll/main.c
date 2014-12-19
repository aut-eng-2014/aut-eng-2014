#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left,*right;
    int value;
} NodeT;

NodeT* createBinTree()
{
    NodeT *p;
    p=(NodeT*)malloc(sizeof(NodeT));
    int c;
    scanf("%d",&c);
    if(c==0)return NULL;
    else
    {
        p->value=c;
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}

void inorder(NodeT *q)
{
    if(q!=NULL)
    {
        inorder(q->left);
        printf("%d", q->value);
        inorder(q->right);
    }
}
// Functia face traversarea inorder a arborelui si schimba pointer-ul din stanga folosind nodul precedent prin care a trecut
void PreviousPointr(NodeT *root)
{
    static NodeT *prev = NULL;

    if (root != NULL)
    {
        PreviousPointr(root->left);
        root->left = prev;
        prev=root;
        PreviousPointr(root->right);
    }
}
// Schimba pointer-ul din dreapta sa functioneze ca next pointer in lista
NodeT *NextPointr(NodeT *root)
{
    NodeT *prev = NULL;
    // Gaseste nodul cel mai din dreapta al arborelui sau ultimul nod al listei
    while (root && root->right != NULL)
        root = root->right;
        // Porneste de la nodul cel mai din dreapta si face traversarea folosind pointerii din stanga, schimband nodurile din dreapta
        while (root && root->left != NULL)
    {
        prev = root;
        root = root->left;
        root->right = prev;
    }
        return (root);
}
// Functia care converteste arborele in lista si returneaza capul(head) listei
NodeT *BTToDLL(NodeT *root)
{
    PreviousPointr(root);

    return NextPointr(root);
}

//Traverseaza lista stanga-dreapta
void printList(NodeT *root)
{
    while (root != NULL)
    {
        printf("%d ", root->value);
        root = root->right;
    }
}

int main()
{

    NodeT *root;
    root=(NodeT*)malloc(sizeof(NodeT));
    root=createBinTree();

    printf("\nInorder Tree Traversal\n");
    inorder(root);

    NodeT *head = BTToDLL(root);

    printf("\nDoublyLinkedList Traversal\n");
    printList(head);
    return 0;
}
