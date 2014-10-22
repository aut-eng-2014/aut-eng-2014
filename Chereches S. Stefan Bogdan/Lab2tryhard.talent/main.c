#include <stdio.h>
#include <stdlib.h>



typedef struct nodet
{
    int key;
    struct nodet* prev;
    struct nodet* next;
} node_t;

node_t *first,*last;

void init()
{
    first = 0;
    last = 0;
    first=(node_t*)malloc(sizeof(node_t));
    last=(node_t*)malloc(sizeof(node_t));

    first->key=6;
    first->next=last;
    first->prev=NULL;
    last->key=5;
    last->prev=first;
    last->next=NULL;
}

void addfirst(int key)
{
    node_t *newN=(node_t*)malloc(sizeof(node_t));
    newN->prev=NULL;
    first->prev=newN;
    newN->next=first;
    newN->key=key;

    first=newN;


}

void addlast(int key)
{
    node_t *newN=(node_t*)malloc(sizeof(node_t));
    last->next=newN;
    newN->prev=last;
    newN->next=NULL;
    newN->key=key;
    last=last->next;

}

node_t *keyfind(int key)
{
    node_t *temp;
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

void removekey(int key)
{
    node_t *temp=(node_t*)malloc(sizeof(node_t));
    temp->key=key;

    if ((first == NULL) && (last ==NULL))
    {
        free(temp);
    }
    else if(key == first->key)
    {
        first = last -> next;
        first -> prev =NULL;
        free(temp);
    }
    else if (key == last->key)
    {
        last = last -> prev;
        last -> next = NULL;
        free(temp);
    }
    else
    {
        temp -> next -> prev = temp -> prev;
        temp -> prev -> next = temp -> next;
        free(temp);
    }

}

int count()
{
    int i=0;
    node_t *temp;
    temp=first;
    while (temp != 0)
    {
        temp=temp->next;
        i++;
    }
    return i;
}

void InsertionSort()
{
    int aux;
    node_t *temp=(node_t*)malloc(sizeof(node_t));
    node_t *temp1=(node_t*)malloc(sizeof(node_t));
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
    node_t *temp,*current,*nextone;
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

void afisare()
{
    node_t *temp;
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
    addfirst(12);
    addlast(9);
    n=count();

    afisare();
node_t *b=keyfind(4);
if(b!=NULL)

{
    printf("%d",b->k);
}
else{printf("Valoarea nu exista");}

    removekey(2);
    afisare();
    printf("%d",count());




    return 0;
}
