#include <stdio.h>
#include <stdlib.h>

typedef struct NodeT
{
    int value;
    struct node *next;
    struct node *previous;
}NodeT;

typedef struct LisT
{
    int key;
    NodeT *first;
    NodeT *last;
}LisT;

LisT *mylist;
NodeT *first,*last;

void initiate(int val1, int val2)
{
    mylist=(LisT*)malloc(sizeof(LisT));
    first=(NodeT*)malloc(sizeof(NodeT));
    last=(NodeT*)malloc(sizeof(NodeT));

    mylist->first=first;
    mylist->last=last;
    first->next=last;
    last->previous=first;

    mylist->first->next=mylist->last;
    mylist->last->previous=mylist->first;

    mylist->last->next=NULL;
    mylist->first->previous=NULL;

    mylist->first->value=val1;
    mylist->last->value=val2;
}

void addfirst (int val)
{
    NodeT *p;
    p=(NodeT*)malloc(sizeof(NodeT));

    mylist->last->next=NULL;
    mylist->first->previous=NULL;

    if(mylist->first==NULL)
    {
        mylist->first=mylist->last=p;
        p->next=p->previous=NULL;
        p->value=val;
    }

    else
    {
        p->next=mylist->first;
        p->previous=NULL;
        mylist->first->previous=p;
        mylist->first=p;
        p->value=val;
    }
}

void addlast (int val)
{
    NodeT *p;
    p=(NodeT*)malloc(sizeof(NodeT));

    mylist->last->next=NULL;
    mylist->first->previous=NULL;

    if(mylist->first==NULL)
    {
        p->value=val;
        mylist->first=mylist->last=p;
        p->next=p->previous=NULL;
    }

    else
    {
        p->value=val;
        mylist->last->next=p;
        p->previous=mylist->last;
        mylist->last=p;
    }
}

int Count()
{
    NodeT *p;
    p=(NodeT*)malloc(sizeof(NodeT));

    int rez=0;

    mylist->last->next=NULL;
    mylist->first->previous=NULL;

    p=mylist->first;

    while(p!=NULL)
    {
        rez++;
        p=p->next;
    }

    return rez;

}

void removefirst()
{
    NodeT *p;
    p=(NodeT*)malloc(sizeof(NodeT));

    mylist->last->next=NULL;
    mylist->first->previous=NULL;

    p=mylist->first;
    mylist->first=mylist->first->next;
    free(p);

    if(mylist->first==NULL)
    {
        mylist->last=NULL;
    }

    else
    {
        mylist->first->previous=NULL;
    }
}

void removelast()
{
    NodeT *p;
    p=(NodeT*)malloc(sizeof(NodeT));

    mylist->last->next=NULL;
    mylist->first->previous=NULL;

    p=mylist->last;
    mylist->last=mylist->last->previous;
    free(p);

    if(mylist->last==NULL)
    {
        mylist->first=NULL;
    }
    else
    {
        mylist->last->next=NULL;
    }
}

void bubblesort()
{
    NodeT *p,*q,*aux;
    p=(NodeT*)malloc(sizeof(NodeT));
    q=(NodeT*)malloc(sizeof(NodeT));
    aux=(NodeT*)malloc(sizeof(NodeT));

    mylist->last->next=NULL;
    mylist->first->previous=NULL;

    for(p=mylist->first;p!=NULL;p=p->next)
        for(q=p->next;q!=NULL;q=q->next)
        {
            if(p->value>q->value)
            {
                aux->value=p->value;
                p->value=q->value;
                q->value=aux->value;
            }
        }
    printf("\n");
    for(p=mylist->first;p!=NULL;p=p->next)
    {
        printf("%d ", p->value);
    }
}

void searchbyvalue(int val)
{
    NodeT *p;
    p=(NodeT*)malloc(sizeof(NodeT));

    int nr=0;

    mylist->last->next=NULL;
    mylist->first->previous=NULL;

    for(p=mylist->first;p!=NULL;p=p->next)
    {
        if(p->value==val)
        {
            nr++;
        }
    }
    printf("In the list are %d elements with the value %d",nr,val);
}
void traverse()
{
    NodeT *p;
    p=(NodeT*)malloc(sizeof(NodeT));

    mylist->last->next=NULL;
    mylist->first->previous=NULL;

    printf("\n The elements of the list are now: ");

    for(p=mylist->first;p!=NULL;p=p->next)
    {
        printf("%d ", p->value);
    }

    printf("\n");
}

int main()
{
    int x,value,val1,val2;

    printf("WELCOME to my HOMEWORK!\n");
    printf("Press 1 to INITIATE the list\n");
    printf("Press 2 to ADD AN ELEMENT AT THE BEGINNING of the list\n");
    printf("Press 3 to ADD AN ELEMENT AT THE END of the list\n");
    printf("Press 4 to REMOVE AN ELEMENT FOROM THE BEGINNING of the list\n");
    printf("Press 5 to REMOVE AN ELEMENT FOROM THE END of the list\n");
    printf("Press 6 to SORT THE VALUES from the list\n");
    printf("Press 7 to SEARCH AN ELEMENT BY ITS VALUE in the list\n");
    printf("Press 8 to COUNT THE ELEMENTS  of the list\n");
    printf("Press 9 to TERMINATE THE PROGRAM\n");

    while(1)
    {
        scanf("%d",&x);
        if(x==9)
        {
            break;
        }
        if(x==1)
        {
            printf("Please insert the first two values of the list:\n");
            printf("value1= ");
            scanf("%d",&val1);
            printf("\nvalue1= ");
            scanf("%d",&val2);
            initiate(val1,val2);
            traverse();
        }
        if(x==2)
        {
            printf(" Please insert the value you want to insert: ");
            scanf("%d", &value);
            addfirst(value);
            traverse();
        }
        if(x==3)
        {
            printf(" Please insert the value you want to insert: ");
            scanf("%d", &value);
            addlast(value);
            traverse();
        }
        if(x==4)
        {
            removefirst(value);
            traverse();
        }
        if(x==5)
        {
            removelast(value);
            traverse();
        }
        if(x==6)
        {
            printf(" The sorted values are: ");
            bubblesort();
        }
        if(x==7)
        {
            printf(" Please insert the value you want to search for in the list: ");
            scanf("%d", &value);
            searchbyvalue(value);
        }
        if(x==8)
        {
            printf("There are %d elements in the list\n",Count());
        }
    }

    return 0;
}
