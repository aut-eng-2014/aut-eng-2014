#include <stdio.h>
#include <stdlib.h>


typedef struct list
{
    int nod;
    struct list *urm;
} NodeT;


void CreateVoidStack ( NodeT **prim )
{

    *prim = NULL;
}


NodeT *createstackelement ( int val )
{

    NodeT *elem;

    elem = ( NodeT* ) malloc ( sizeof (NodeT) );

    if ( elem == NULL )
    {

        perror ( "\nMemory not allocated! \n " );
        exit ( 1 );
    }

    elem->nod = val;
    elem->urm = NULL;

    return elem;

}

void push ( NodeT **prim, int p )
{

    NodeT *elem = createstackelement( p );



    if ( *prim == NULL )
    {

        *prim = elem;
    }
    else
    {
        //adds first node

        elem->urm = *prim;
        *prim = elem;

    }

}

void freenode ( NodeT **p )
{
    free( *p );

}
int *pop ( NodeT **prim )
{



    if ( *prim == NULL )
    {

        printf ( "\nStack is empty!\n" );
        return;
    }


    //delete 1st element

    NodeT *aux = *prim;
    NodeT *p = (*prim);


    *prim = aux->urm;
   // freenode ( &aux );

    return p->nod;

}
int n, viz[100], a[100][100];
void read()
{
    FILE *f=fopen("date.in", "r");

    if(f==NULL)
    {
        perror("msg:");
        exit(1);
    }
    int i, j;
    fscanf(f, "%d", &n);


    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            fscanf(f, "%d", &a[i][j]);


}

void dfs(NodeT **prim, int k)
{

    push(&(*prim), k);
    int i;
    while(*prim!=NULL)
    {
        int aux=pop(&(*prim));

        if(!viz[aux])
        {

            viz[aux]=1;
            printf("%d ", aux);

            for(i=1; i<=n; i++)
                if( viz[i]==0 && a[aux][i]==1 )
                {
                    push(&(*prim), i);


                }

        }
    }



}

void addQ(NodeT **prim, int val)
{

    NodeT *p=createstackelement(val);

    if( *prim ==NULL)
    {
        *prim=p;

    }
    else
    {
        NodeT *q, *q1;

        q=*prim;

        while(q->urm!=NULL)
        {
        q=q->urm;
        }
        q->urm=p;



    }


}

int popQ(NodeT **prim)
{

    if( *prim == NULL)
    {
        printf("\nEmpty Queue\n");
        return;
    }
    else
    {

        NodeT *p;

        p=*prim;
        (*prim)=(*prim)->urm;

        return p->nod;
    }


}
int viz2[100];


void bfs( NodeT **prim, int k)
{
    viz2[k]=1;
    addQ(&(*prim), k);

    while(*prim != NULL)
    {

        printf("%d ", popQ(&(*prim)));

        int i;
        for(i=1; i<=n; i++)
            if(viz2[i]==0 && a[k][i]==1)
            {

                viz2[i]=1;
                addQ(&(*prim), i);


            }

    }



}


int main()
{
    NodeT *prim, *primQ;

    CreateVoidStack(&prim);
    CreateVoidStack(&primQ);

    read();

    int i;
    printf("DFS: ");
    dfs(&prim, 1);

    for(i=1; i<=n; i++)
        if(!viz[i])
            dfs(&prim, i);

    printf("\nBFS: ");

    bfs(&primQ, 1);
    for(i=1; i<=n; i++)
        if(!viz2[i])
        bfs(&prim, i);

    return 0;
}
