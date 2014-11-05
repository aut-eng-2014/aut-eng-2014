#include "functions.h"
#include <limits.h>

int power(int x, int n)
{
    int i;
    if (n==1)
        return x;
    if (n<0)
        return 1; ///it is mathematically incorrect, but will suffice for the current case
    int y=x;
    for (i=1;i<n;i++)
        y*=x;
    return y;
}

node* insertNode(node* np,int n)///with the number of elements we would use here, i highly doubt recursivity would cause stack overflow
{
    static int dpt=-1;
    dpt++;
    if (dpt>5)
    {
        printf("Maximum depth of %d exceeded\n",dpt-1);
        dpt--;
        return NULL;
    }
    if (np==NULL)
    {
        np=(node*)malloc(sizeof(node));;

        np->val=n;
        np->left=NULL;
        np->right=NULL;
    }
    else
    {
        if (n<np->val)
        {
            np->left=insertNode(np->left,n);
        }
        else
        if (n>np->val)
        {
            (np->right=insertNode(np->right,n));
        }
    }
    dpt--;
    return np;
}

void preorder(node * np)
{
    if (np!=NULL)
    {
        printf("%d | ",np->val);
        preorder(np->left);
        preorder(np->right);
    }
}

void findNode(node * root,int n)
{
    if (root!=NULL)
    {
        if (root->val==n)
        {
            printf("Node containg %d exists.\n",n);
        }
        else
            if (n<root->val)
            {
                findNode(root->left,n);
            }
            else
            {
                findNode(root->right,n);
            }
    }
    else
    {
        printf("Node containing %d not found.\n",n);
    }
}

void deleteNode(node* np,int n)
{
    static node* last;
    if (np!=NULL) ///1. not found
    {
        if (np->val!=n)///if not null and == means that found the node, therefore it will skip to the 2. with the last its parent value
        {
            last=np;///value not yet found, but suppose that the next one will be correct, or NULL
            if (n<np->val)
            {
                deleteNode(np->left,n);
            }
            else
            {
                deleteNode(np->right,n);
            }
        }
        if (np->val==n)
        {
            if ((np->left==NULL) && (np->right==NULL))
            {
                if (last->left==np)
                {
                    last->left=NULL;
                }
                else
                {
                    last->right=NULL;
                }
                free(np);
                np=NULL;
                return;
            }
            if ((np->left!=NULL) && (np->right!=NULL))
            {
                node * t=np->left;
                last=np;///in this particular case, last is not needed for np, but for t
                while (t->right!=NULL)
                {
                    last=t;
                    t=t->right;
                }
                np->val=t->val;

                if (last->left==t)
                {
                    last->left=NULL;
                }
                else
                {
                    last->right=NULL;
                }
                free(t);
                t=NULL;
                return;
            }
            ///the only remaining option is that only one of them is NULL
            if (last->left==np)
            {
                last->left=(np->left!=NULL?np->left:np->right);///selects the non-NULL child
                free(np);
                np=NULL;
            }
            else///np->right
            {
                last->right=(np->left!=NULL?np->left:np->right);
                free(np);
                np=NULL;
            }
        }
    }
    else
    {
        return;///1. therefore terminates
    }

}

int findMaxDepth(node * np,int * md)///md as in maxDepth
{
    static int cd=-1;
    if (np!=NULL)
    {
        cd++;
        if (cd>*md)
            *md=cd;
        findMaxDepth(np->left,md);
        findMaxDepth(np->right,md);
        cd--;
    }
    return *md;
}

int findAllNodesThatAreOfDepthDepth(node * np, int * a, int d,int *n)
{
    static int cd=-1;///Current depth
    if (a==NULL)
    {
        a=(int*)malloc(33*sizeof(int));
        a[0]=INT_MAX;
    }
    if (np!=NULL)
    {
        cd++;
        if (d==0)
        {
            a[*n]=np->val;
            (*n)++;///to change n, I need a pointer to it. To increase it's value i need (*n)++;
            a[*n]=INT_MAX;
            cd--;
            return *n;
        }
        if (cd+1==d)
        {
            a[*n]=(np->left==NULL?INT_MIN:np->left->val);
            (*n)++;
            a[*n]=(np->right==NULL?INT_MIN:np->right->val);
            (*n)++;
            a[*n]=INT_MAX;
        }
        if (cd+1<d)
        {
            findAllNodesThatAreOfDepthDepth(np->left,a,d,n);
            findAllNodesThatAreOfDepthDepth(np->right,a,d,n);
        }
        cd--;
    }

    return *n;
}

void prettyPrint(node * np)
{
    int md=-1;///maxdepth
    findMaxDepth(np,&md);

    int *a=(int*)malloc(33*sizeof(int));///array to store the values in. For so few values(max 32 specified) I don't see how a linked list would be more advantageus
    int nodeCount=0;

    int i;
    for (i=0;i<=md;i++)
    {
        findAllNodesThatAreOfDepthDepth(np,a,i,&nodeCount);
        int j;
        for (j=0;j<nodeCount;j++)
        {
            int k;
            for (k=0;k<(power(2,md+2-i)-3)/(j==0?2:1);k++)
            {
                printf(" ");
            }
            if (a[j]!=INT_MIN)
                printf("%3d",a[j]);
            else
                printf("   ");///3 spaces
        }
        a[0]=INT_MAX;
        nodeCount=0;
        printf("\n");
    }
}
