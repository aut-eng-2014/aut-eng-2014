#include <stdio.h>
#include <stdlib.h>


typedef struct stiva
{
    int nod;
    struct stiva *urm;
} Stiva;


void creezStivaVida ( Stiva **prim )
{

    *prim = NULL;
}


Stiva *crezElemStiva ( int val )
{

    Stiva *elem;

    elem = ( Stiva* ) malloc ( sizeof (Stiva) );

    if ( elem == NULL )
    {

        perror ( "\nFunctia: *creeazaElemStiva(Arbore), nu a putut aloca memorie! \n " );
        exit ( 1 );
    }

    elem->nod = val;
    elem->urm = NULL;

    return elem;

}

void push ( Stiva **prim, int p )
{

    Stiva *elem = crezElemStiva ( p );



    if ( *prim == NULL )
    {

        *prim = elem;
    }
    else
    {
        //adaug nodul in fata primului nod

        elem->urm = *prim;
        *prim = elem;

    }

}

void elibNod ( Stiva **p )
{
    free( *p );

}
int *pop ( Stiva **prim )
{



    if ( *prim == NULL )
    {

        printf ( "\nNu aveti ce sterge! Stiva e vida!\n" );
        return;
    }


    //sterg primul element din lista

    Stiva *aux = *prim;
    Stiva *p = (*prim);


    *prim = aux->urm;
   // elibNod ( &aux );

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

void dfs(Stiva **prim, int k)
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

void addQ(Stiva **prim, int val)
{

    Stiva *p=crezElemStiva(val);

    if( *prim ==NULL)
    {
        *prim=p;

    }
    else
    {
        Stiva *q, *q1;

        q=*prim;

        while(q->urm!=NULL)
        {
        q=q->urm;
        }
        q->urm=p;



    }


}

int popQ(Stiva **prim)
{

    if( *prim == NULL)
    {
        printf("\nCoada e goala\n");
        return;
    }
    else
    {

        Stiva *p;

        p=*prim;
        (*prim)=(*prim)->urm;

        return p->nod;
    }


}
int viz2[100];


void bfs( Stiva **prim, int k)
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
    Stiva *prim, *primQ;

    creezStivaVida(&prim);
    creezStivaVida(&primQ);



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
    //printf("Hello world!\n");

    return 0;
}
