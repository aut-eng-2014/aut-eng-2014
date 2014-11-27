#include <stdio.h>
#include <stdlib.h>

typedef struct bst
{
    int value;
    struct bst *left,*right,*ky;
} NodeT;

NodeT *root;

NodeT *insert(NodeT *root, int key)
{
    NodeT *p;
    if(root==0)
    {
        p=(NodeT*)malloc(sizeof(NodeT));
        p->ky=key;
        p->left=0;
        p->right=0;
        return p;
    }
    else if(key<root->ky) root->left=insert(root->left,key);
    else if(key>root->ky) root->right=insert(root->right,key);
    else
    {
        printf("\nKey already exists: %d\n",key);
    }
    return root;
}

NodeT *srch(NodeT *root,int key)
{
    NodeT *p;
    if(root==0)return 0;
    p=root;
    while(p!=0)
    {
        if(p->ky==key)return p;
        else if(key<p->ky)p=p->left;
        else p=p->right;
    }
    return 0;
}

void preorder(NodeT *p,int level)
{

    int i;
    if(p!=0)
    {
        for(i=0; i<=level; i++)printf(" ");
        printf("%2d\n",p->ky);
        preorder(p->left, level+1);
        preorder(p->right, level+1);
    }
}

void inorder(NodeT *p, int level)
{
    int i;
    if(p!=0)
    {
        inorder(p->left, level+1);
        for(i=0; i<=level; i++)printf(" ");
        printf("%2d\n",p->ky);
        inorder(p->right, level+1);
    }
}

void postorder(NodeT *p, int level)
{
    int i;
    if(p!=0)
    {
        postorder(p->left, level+1);
        postorder(p->right, level+1);
        for(i=0; i<=level; i++)printf(" ");
        printf("%2d\n",p->ky);
    }
}

NodeT *del(NodeT *root, int key)
{
    NodeT *p,*father;
    NodeT *preplace, *freplace;
    int dir;
    if(root==0)return 0;
    p=root;
    father=0;
    while((p!=0)&&(p->ky!=key))
    {
        if(key<p->ky)
        {
            father=p;
            p=p->left;
            dir=1;
        }
        else
        {
            father=p;
            p=p->right;
            dir=2;
        }
    }
    if(p==0)
    {
        printf("\nThere is no node with key=%d\n", key);
        return root;
    }
    if(p->left==0)preplace=p->right;
    else if(p->right==0)preplace=p->left;
    else
    {
        freplace=preplace;
        preplace=preplace->left;
        while(preplace->left!=0)
        {
            freplace=preplace;
            preplace=preplace->left;
        }
        if(freplace!=p)
        {
            freplace->left=preplace->right;
            preplace->right=p->right;
        }
        preplace->left=p->left;
    }
    free(p);
    printf("\nNode of key = %d was deleted!",key);
    if(father==0)return preplace;
    else
    {
        if(dir==1)father->left=preplace;
        else father->right=preplace;
    }

}

void main()
{
    char choice;
    char ans = 'n';
    int key;
    NodeT *root, *tmp;
    root = NULL;

    do
    {
        printf("\n1.For Insert Press: i");
        printf("\n2.For Find Press:   f");
        printf("\n3.For Delete Press: d");
        printf("\n4.For Show Press:   s");
        printf("\n5.For Quit Press:   q");
        printf("\n\nEnter your choice: ");
        scanf("%c", &choice);

        switch (choice)
        {
        case 'i':
            do
            {
                printf("\nEnter The Element: ");
                scanf("%d", &key);
                root=insert(root, key);
                printf("\nWant To Enter More Elements?(y/n)");
                ans = getch();
            }
            while (ans == 'y');
            break;

        case 'f':
            do
            {
                printf("\nEnter Element to be searched :");
                scanf("%d", &key);
                tmp = srch(root,key);
                printf("\nAdress of node %d is %d", key, tmp);
                printf("\nWant To Find More Elements?(y/n)");
                ans = getch();
            }
            while (ans == 'y');
            break;

        case 'd':
            do
            {
                printf("\nEnter Element to be deleted : ");
                scanf("%d",&key);
                tmp = del(root,key) ;
                printf("The Element %d has been deleted",&key);
                printf("\nWant To Delete More Elements?(y/n)");
                ans = getch();
            }
            while (ans == 'y');
            break;

        case 's':
            if (root == NULL)
                printf("Tree Is Not Created");
            else
            {
                printf("\nThe Preorder display : \n");
                preorder(root,0);
                printf("\nThe Inorder display : \n");
                inorder(root,0);
                printf("\nThe Postorder display : \n");
                postorder(root,0);

            }
            break;
        }
    }
    while (choice != 'q');
}
