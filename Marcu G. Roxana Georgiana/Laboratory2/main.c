#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next, *prev;
} NodeT;

NodeT *first,*last;

void init()
{
    first=(NodeT*)malloc(sizeof(NodeT));
    last=(NodeT*)malloc(sizeof(NodeT));

    first->next=last;
    first->prev=NULL;
    first->value=1;
    last->prev=first;
    last->next=NULL;
    last->value=2;
}

void traversal()
{
    NodeT *temp=first;
    while(temp != NULL)
    {
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("\n\n");
}

void addlast(int value)
{
    NodeT *newN=(NodeT*)malloc(sizeof(NodeT));
    newN->value=value;
    last->next=newN;
    newN->prev=last;
    newN->next=NULL;
    last=newN;
}

void addfirst(int value)
{
    NodeT *newN=(NodeT*)malloc(sizeof(NodeT));
    newN->value=value;
    newN->next=first;
    first->prev=newN;
    first=newN;
}

int countt()
{
    NodeT *temp=first;
    int nr=0;
    while(temp != NULL)
    {
        nr++;
        temp=temp->next;
    }
    return nr;
}

void removee(int value)
{
    int ok=0;
    NodeT *current=first;
    if( current->value == value )
    {
        first=first->next;
        first->prev=NULL;
        ok=1;
    }
    else
    {
        while( current->next != NULL )
        {
            if(current->value == value)
            {
                ok=2;
                break;
            }
            current=current->next;
        }
    }
    if(ok == 2)
    {
        current->prev->next=current->next;
        current->next->prev=current->prev;
    }


    if(ok==0 && current->next == NULL && current->value == value )
    {
        current->next->prev=NULL;
        ok=3;
    }

    if(ok == 0)
        printf("The element can't be removed from the list because it wasn't found\n\n");
    else
    {
        printf("\nThe list without the value %d is\n ",value);
        traversal();
    }

}


void searchh(int value)
{
    NodeT *f=first,*l=last;
    int i=1,nr,ok=0;
    nr=countt();
        while(i <= nr/2 )
        {
            if(f->value == value || l->value == value)
            {
                ok=1;
                break;
            }
            f=f->next;
            l=l->prev;
            i++;
        }

    if( ok==0 && nr%2!=0 && f->value==value)
        ok=1;

    if( ok == 0 )
            printf("The value wasn't found\n\n");
            else
                printf("The value was found\n\n");

}


void bubblesort(int value)
{
    NodeT *temp1=first;
    NodeT *temp2=first->next;
    int aux;
    while(temp1->next != NULL)
        {
            while(temp2 != NULL)
            {
                if(value == 1)
                {
                    if(temp1->value > temp2->value)
                    {
                        aux=temp1->value;
                        temp1->value=temp2->value;
                        temp2->value=aux;
                    }
                }
                else
                {
                    if(temp1->value < temp2->value)
                    {
                        aux=temp1->value;
                        temp1->value=temp2->value;
                        temp2->value=aux;
                    }
                }
                 temp2=temp2->next;

            }
            temp1=temp1->next;
            temp2=temp1->next;
        }
}


    int main()
    {
    int nr;
    init();
    printf("The list is\n");
    traversal();


    printf("Write the number you want to add at the beginning ");
    scanf("%d",&nr);
    addfirst(nr);
    traversal();

    printf("Write the number you want to add at the end ");
    scanf("%d",&nr);
    addlast(nr);
    traversal();

    printf("Write the number you want to remove from the list ");
    scanf("%d",&nr);
    removee(nr);

    int n=countt();
    printf("The list has %d elements\n\n",n);

    printf("Write the number you want to find in the list ");
    scanf("%d",&nr);
    searchh(nr);

    int mode;
    printf("Press 1 if you want to sort the list ascending,or 0 for descending ");
    scanf("%d",&mode);
    bubblesort(mode);
    traversal();

    return 0;
    }
