#include <stdio.h>
#include <stdlib.h>
//Read a mathematical expression, in postfix form
struct node
{
    char data;
    struct node *leftnode;
    struct node *rightnode;
};
struct node *stc[30],*temp,*root;

typedef struct node *NodePointer;

char expression[50];
char c;
int top=0;
NodePointer pop();

void push(NodePointer);
void getinput();
void inorder(NodePointer p);

int main ()
{
    getinput();
    int i;
    for(i=0; i<strlen(expression); i++)
    {
      //  printf("\nstrlength=%d--------for i=%d\n",strlen(expression),i);
        c=expression[i];
        switch(c)
        {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        {
            temp=(NodePointer)malloc(sizeof(struct node));
            temp->data=c;
            temp->rightnode=pop();
            temp->leftnode=pop();
            push(root);
        }
        default :
        {
            temp=(NodePointer)malloc(sizeof(struct node));
            temp->data=c;
            temp->leftnode=NULL;
            temp->rightnode=NULL;
            push(temp);
        }
        break;
        }
    }
    root=pop();
    inorder(root);
    getch();
}
NodePointer pop(NodePointer p)
{
    if(top==0)
        printf("Underflow condition !!");
    else
    {
        // printf("\npopped  \n");
        return(stc[top--]);
    }
}
void push(NodePointer p)
{
    if(top==29)
        printf("Overflow condition !!");
    else
    {
        //printf("pushed ");
        stc[++top]=p;
    }
}
void getinput()
{
    printf("Enter a postfix mathematical expression : ");
    gets(expression);
}

void inorder(NodePointer p)
{
    if(p!=NULL)
    {
        inorder(p->leftnode);
        printf("Data :%c",p->data);
        inorder(p->rightnode);
    }
    else
    {
        printf("\n Null \n");
        return;
    }
    /*
    void Preorder(struct node* root)
    {
        if(root==NULL)
            return;
        printf("%c",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }

void Postorder(struct node* root)
{
    if(root==NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%c",root->data);

}*/
}
