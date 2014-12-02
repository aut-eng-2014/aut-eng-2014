#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *left, *right;
}NodeT;

NodeT *root=NULL;

void insertNode(int nr)
{
    NodeT *p, *q;
    p = ( NodeT *) malloc( sizeof(NodeT) ) ;
    p->val=nr;
    p->left=NULL;
    p->right=NULL;

    if (root == NULL)
    {
        root=p;
        return;
    }
    else
    {
        q=root;
        for (;;)
        {
            if (nr < q->val)
            {
                if (q->left==NULL)
                {
                    q->left=p;
                    return;
                }
                else
                {
                    q=q->left;
                }
            }
            else
                if (nr > q->val)
                {
                    if (q->right == NULL)
                    {
                        q->right=p;
                        return;
                    }
                    else
                    {
                        q=q->right;
                    }
                }
                else
                {
                    printf("The node %d already exists, do nothing & return\n",nr);
                    free(p);
                    return;
                }
            }
        }
}

void inorder(NodeT *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

void preorder(NodeT *root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NodeT *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
    }
}


int height(NodeT* root)
{
	if(root == NULL)
		return 0;
	else
	{
		int left  = height(root->left);
		int right = height(root->right);
		if(left >= right)
			return left + 1;
		else
			return right + 1;
	}
}

void findNode(int value)
{
    int found=0;
    NodeT *temp=root;
    if (value == temp->val)
        {printf("The node %d has been found\n", value); found=1;}
    else
        while (temp->left != NULL || temp->right != NULL)
        {
            if (value < temp->val)
            {
                if (temp->left->val==value)
                {
                    printf("The node %d has been found\n", value); found=1;
                    return;
                }
                else
                {
                    temp=temp->left;
                }
            }
            else
                if (value > temp->val)
                {
                    if (temp->right->val == value)
                    {
                        printf("The node %d has been found\n", value); found=1;
                        return;
                    }
                    else
                    {
                        temp=temp->right;
                    }
                }

            }
    if (found==0)
        printf("The node %d doesn't exist\n",value);
    return;


}

NodeT *delNode(NodeT *root , int key )
{
    NodeT *p,*pParent,*pRep, *pRepParent;
    int dir; //left=1; right=0;

    if (root==NULL) return NULL; //empty tree
    p=root;
    pParent=NULL;

    while (p!=NULL && p->val!=key)
    {
        if (key < p->val)
        {
            pParent=p;
            p=p->left;
            dir=1;
        }
        else
        {
            pParent=p;
            p=p->right;
            dir=0;
        }
    }
    if (p == NULL)
     {
        printf("The node hasn't been found\n");
        return root;
     }

     if (p->left=NULL)
        pRep=p->right;
     else if (p->right=NULL)
        pRep=p->left;
     else
     {
         //has both children
         pRepParent=p;
         pRep=p->right;
         while (pRep->left!=NULL)
         {
             pRepParent=pRep;
             pRep=pRep->left;
         }
         if (pRepParent!=p)
         {
             pRepParent->left=pRep->right;
             pRep->right=p->right;
         }
         pRep->left=p->left;
     }
     free(p);
     printf("The node %d has been deleted\n", key);
     if (pParent==NULL)
        return pRep;
     else
     {
        if (dir==1)
            pParent->left=pRep;
        else
            pParent->right=pRep;
        return root;
     }
}


int main()
{
    int nodeval;
 printf("\nI.Insert   D.Delete    F.Find  S.Show  Q.Quit\n");
 for (;;)
 {
     char input=toupper(getc(stdin));
     if (input == '\n') printf("\nI.Insert   D.Delete    F.Find  S.Show  Q.Quit\n");
     switch(input)
     {
         case 'I':  printf("node=");
                    scanf("%d",&nodeval);
                    insertNode(nodeval);
                    printf("node %d has been inserted\n", nodeval);
                    break;

         case 'S':  inorder(root); printf("\n");
                    preorder(root);  printf("\n");
                    postorder(root);  printf("\n");
                    break;

         case 'F':  printf("nodeToFind=");
                    scanf("%d",&nodeval);
                    findNode(nodeval);
                    break;
         case 'D':  scanf("%d", &nodeval);
                    root=delNode(root, nodeval );
                    break;

         case 'Q': return 0; break;
     }

 }

return 0;
}
