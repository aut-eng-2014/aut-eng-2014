#include <stdio.h>
#include <stdlib.h>


typedef struct list
{
    int node;
    struct list *next;
} NodeT;


void CreateVoidStack(NodeT **first)
{
    *first=NULL;
}


NodeT *CreateStackElement(int val)
{

    NodeT *elem=(NodeT*)malloc(sizeof(NodeT));

    if(elem==NULL)
    {
        perror("\nNo memory allocated.\n");
        exit(1);
    }

    elem->node=val;
    elem->next=NULL;

    return elem;

}

void push(NodeT **first, int p)
{
    NodeT *elem=CreateStackElement(p);

    if(*first==NULL )
    {

        *first=elem;
    }
    else
    {
        //adds first node
        elem->next=*first;
        *first=elem;
    }
}


void freenode(NodeT **p)
{
    free(*p);
}


int *pop(NodeT **first)
{
    if(*first==NULL)
    {
        printf ("\nStack is empty.\n");
        return;
    }

    //deletes the 1st element

    NodeT *aux = *first;
    NodeT *p =(*first);
    *first=aux->next;

    return p->node;
}


int n, viz[100], a[100][100];


void read()
{
    FILE *f=fopen("date.in", "r");

    if(f==NULL)
    {
        perror("Msg:");
        exit(1);
    }
    int i,j;
    fscanf(f, "%d", &n);


    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            fscanf(f, "%d", &a[i][j]);


}

void dfs(NodeT **first, int k)
{
    push(&(*first), k);
    int i;
    while(*first!=NULL)
    {
        int aux=pop(&(*first));

        if(!viz[aux])
        {

            viz[aux]=1;
            printf("%d ", aux);

            for(i=1; i<=n; i++)
                if( viz[i]==0 && a[aux][i]==1 )
                {
                    push(&(*first), i);
                }
        }
    }
}


void addQ(NodeT **first, int val)
{
    NodeT *p=CreateStackElement(val);

    if(*first==NULL)
    {
        *first=p;
    }
    else
    {
        NodeT *q;
        q=*first;

        while(q->next!=NULL)
        {
         q=q->next;
        }
         q->next=p;
    }
}

int popQ(NodeT **first)
{
    if(*first==NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }
    else
    {
        NodeT *p;

        p=*first;
        (*first)=(*first)->next;

        return p->node;
    }
}

int viz2[100];


void bfs( NodeT **first, int k)
{
    viz2[k]=1;
    addQ(&(*first),k);

    while(*first!=NULL)
    {

        printf("%d ", popQ(&(*first)));

        int i;
        for(i=1; i<=n; i++)
            if(viz2[i]==0 && a[k][i]==1)
            {
                viz2[i]=1;
                addQ(&(*first), i);
            }
    }
}

int main()
{
    NodeT *first, *firstQ;

    CreateVoidStack(&first);
    CreateVoidStack(&firstQ);

    read();

    int i;
    printf("\nDFS: ");
    dfs(&first, 1);

    for(i=1; i<=n; i++)
        if(!viz[i])
            dfs(&first, i);

    printf("\nBFS: ");

    bfs(&firstQ, 1);
    for(i=1; i<=n; i++)
        if(!viz2[i])
        bfs(&first,i);

    return 0;
}
