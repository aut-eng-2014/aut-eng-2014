#include <stdio.h>
#include <stdlib.h>

#define LEFT 1
#define RIGHT 2

typedef struct node
{
    int value;
    struct node *left , *right;
}Node;

Node *root;

void preorder(Node *p)
{
    if(p != NULL)
    {
        printf("%d ", p->value);
        preorder(p->left);
        preorder(p->right);
    }
}

void insertN(int val)
{
    Node *p, *q;
    p = (Node*)malloc(sizeof(Node));
    p->value = val;
    p->left = p->right = NULL;

    if(root == NULL)
    {
        root = p;
        return;
    }
    q = root;

    for( ; ; )
    {
        if(val < q->value)
        {
            if(q->left == NULL)
            {
                q->left = p;
                return;
            }
            q = q->left;
        }
        else if(val > q->value)
        {
            if(q->right == NULL)
            {
                q->right = p;
                return;
            }
            q = q->right;
        }
        else
        {
            free(p);
        }
    }
}

Node *findN(Node *root, int val)
{
    Node *p;

    if(root == NULL) return NULL;
    p = root;
    while(p != NULL)
    {
        if(val == p->value) return p;
        else if(val < p->value)
        {
            p = p->left;
            p = p->right;
        }
        else return NULL;
    }
}

Node *minN(Node* p)
{
    Node* current = p;
    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *deleteNode(Node* root, int val)
{

    if (root == NULL) return root;
    if (val < root->value)
        root->left = deleteNode(root->left, val);
    else if (val > root->value)
        root->right = deleteNode(root->right, val);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minN(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

int main()
{
    Node *p;
    int nr=100,i,n,val;
    while(nr)
    {

        printf("\n0.QUIT 1.INSERT 2.DELETE 3.FIND 4.SHOW");
        scanf("%d",&nr);
        switch (nr)
        {
        case 1:
            printf("\nEnter the value you want to insert: ");
            scanf("%d", &val);
            insertN(val);
            preorder(root);
            break;
        case 2:
            deleteNode(root, val);
            break;
        case 3:
            printf("\nEnter the value you want to find: ");
            scanf("%d", &val);
            p = findN(root, val);
            break;
        case 4:
            preorder(root);
        case 0:
            return 0;
            break;
        }
    }
    return 0;
}
