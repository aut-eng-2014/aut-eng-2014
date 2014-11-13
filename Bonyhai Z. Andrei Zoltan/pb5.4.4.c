#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct BST
{
    int data;
    struct BST *stanga, *dreapta;
} nod;
nod *root;
nod *nodnou;
int comanda;
int val;
void preorder(nod *temp)
{
    if (temp != NULL)
    {
        printf("%d", temp->data);
        preorder(temp->stanga);
        preorder(temp->dreapta);
    }
}
void inorder(nod *temp)
{
    if (temp != NULL)
    {
        inorder(temp->stanga);
        printf("%d", temp->data);
        inorder(temp->dreapta);
    }
}
void postorder(nod *temp)
{
    if (temp != NULL)
    {
        postorder(temp->stanga);
        postorder(temp->dreapta);
        printf("%d", temp->data);
    }
}
void inserare(nod *root, nod*nodnou)
{

    if(nodnou->data<root->data)
    {
        if(root->stanga==NULL)
            root->stanga=nodnou;
        else inserare(root->stanga, nodnou);
    }
    if(nodnou->data>root->data)
    {
        if(root->dreapta==NULL)
            root->dreapta=nodnou;
        else inserare(root->dreapta, nodnou);
    }

}
void cautare(nod *root, int key)
{
    nod *temp;
    temp=root;
    while(temp!=NULL)
    {
        if(temp->data=key)
            printf("ELEMENTUL A FOST GASIT ",temp->data);
        if(temp->data>key) temp=temp->dreapta;
        if(temp->data<key) temp=temp->stanga;
    }
    void stergere(nod *root, int key, nod **parinte)
    {
        nod *temp;
        temp=root;
        while(temp!=NULL)
        {
            if(temp->data=key)
            {
                printf("ELEMENTUL A FOST GASIT si va fi sters ",temp->data);
                temp->data=NULL;
            }
            *parinte=temp;
            if(temp->data>key) temp=temp->dreapta;
            if(temp->data<key) temp=temp->stanga;
        }
        int main()
        {
            do
            {
                printf("/n SELECT YOUR COMMAND");
                printf("/n1=INSERT,  2=DELETE,   3=FIND,   4=SHOW");
                scanf("%d",&comanda);
                switch(comanda)
                {
                case 1:
                    inserare(nod *root, nod *nodnou);
                case 2:
                {
                    printf("introd valoarea de sters: ");
                    scanf ("%d", val);
                    sterge(val);
                }
                case 3:
                {
                    printf("introd valoarea cautata: ");
                    scanf("%d", val);
                    cautare(val);
                    case 4:
                    {
                        preorder();
                        inorder();
                        postorder();
                    };
                }
                }
                while (comanda!=0);



            }
