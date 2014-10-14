#include <stdio.h>
#include <stdlib.h>



typedef struct node
{
    int key;
    struct node* prev;
    struct node* next;
} nodeT;

nodeT *first,*last;

void init()
{
    first = 0;
    last = 0;
    first=(nodeT*)malloc(sizeof(nodeT));
    last=(nodeT*)malloc(sizeof(nodeT));

    first->key=6;
    first->next=last;
    first->prev=NULL;
    last->key=5;
    last->prev=first;
    last->next=NULL;
}

void addfirst(int key)
{
    nodeT *newN=(nodeT*)malloc(sizeof(nodeT));
    newN->prev=NULL;
    first->prev=newN;
    newN->next=first;
    newN->key=key;

    first=newN;


}

void addlast(int key)
{
    nodeT *newN=(nodeT*)malloc(sizeof(nodeT));
    last->next=newN;
    newN->prev=last;
    newN->next=NULL;
    newN->key=key;
    last=last->next;

}

nodeT *finde(int key)
{
    nodeT *temp;
    temp = first;
    while ( temp != NULL )
        if( (temp->key== key))
        {
            return temp;
        }
        else
            temp =temp ->next ;
    return NULL;
}

void remov(int key)
{
    nodeT *temp=(nodeT*)malloc(sizeof(nodeT));
    temp=first;
    while(temp!=NULL)
    {

        if ((first == NULL) && (last ==NULL))
        {
            free(temp);
        }
        else
        {
            if(temp->key == key)
            {
                if(temp==first)
                {
                    first = first -> next;
                    first -> prev =NULL;
                    free(temp);
                    break;
                }
                if(temp==last)
                {
                    last = last -> prev;
                    last -> next = NULL;
                    free(temp);
                    break;
                }
                else
                {
                    temp -> next -> prev = temp -> prev;
                    temp -> prev -> next = temp -> next;
                    free(temp);
                    break;
                }
                temp=temp->next;

            }
            else
            {
                temp=temp->next;
            }
        }
    }
}

int numarare()
{
    int i=0;
    nodeT *temp;
    temp=first;
    while (temp != NULL)
    {
        temp=temp->next;
        i++;
    }
    return i;
}

void InsertionSort()
{
    int aux;
    nodeT *temp=(nodeT*)malloc(sizeof(nodeT));
    nodeT *temp1=(nodeT*)malloc(sizeof(nodeT));
    temp=first;
    temp1=first;
    while(temp!=NULL)
    {
        while((temp->key)>=(temp1->next->key))
        {
            aux=temp->key;
            temp->key=temp1->next->key;
            temp1->next->key=aux;
        }
        temp=temp->next;
    }
}

void listsort(int n)
{
    nodeT *temp,*current,*nextone;
    int i,j;
    for(i=0; i<n; i++)
    {
        current = first;
        for(j=0; j<n-1-i; j++ )
        {
            if(current->key > current->next->key)
            {
                nextone = current->next;
                current->next = nextone->next;
                nextone->next = current;
                if(current == first)
                {
                    first = nextone;
                    current = nextone;
                }
                else
                {
                    current = nextone;
                    temp->next = nextone;
                }
            }
            temp = current;
            current = current->next;
        }
    }
}

void afis()
{
    nodeT *temp;
    temp=first;
    while (temp != 0)
    {
        printf("%d  ",temp->key);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int n;
    init();
    addfirst(7);
    addlast(9);
    n=numarare();

    afis();

    nodeT *b=finde(9);
    if(b!=NULL)
        printf("%d",b->key);
    else
        printf("Value not found");
    printf("\n");
    remov(9);
    afis();
    printf("%d",numarare());

    //listsort(n);


    return 0;
}
