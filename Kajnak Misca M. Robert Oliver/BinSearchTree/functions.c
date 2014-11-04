#include "functions.h"

node* insertNode(node* np,int n)///with the number of elements we would use here, i highly doubt recursivity would cause stack overflow
{
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
            np->right=insertNode(np->right,n);
        }
    }
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
