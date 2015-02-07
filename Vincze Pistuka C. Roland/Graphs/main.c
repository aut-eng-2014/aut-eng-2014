#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *next;
}
NodeT;

NodeT *first=NULL;
NodeT *last=NULL;
NodeT *forw=NULL;

int value;

int adj_matrix[10][10];
char vertices[10];

void enqueue(int x)
{
    NodeT *temp;
    temp=(NodeT*) malloc (sizeof(NodeT));
    (*temp).key=x;
    if (first==NULL && last==NULL)
    {
        first=last=temp;
    }
    else
    {
        last->next=temp;
        last=temp;
    }
}

void dequeue ()
{
    NodeT *temp;
    temp=(NodeT*) malloc(sizeof(NodeT));
    temp=first;
    if (first!=NULL)
    {
        first->next=first;
    }
    value=first->key;
    if (first!=last)
    {
        free(temp);
    }
    else
    {
        last=NULL;
    }
}

void push (int x)
{
    NodeT *temp;
    temp=(NodeT*) malloc (sizeof(NodeT));
    temp->key=x;
    temp->next=forw;
    forw=temp;
    value=forw->key;
}

void pop ()
{
    NodeT *temp;
    if (forw==NULL)
    {
        printf ("Stack is empty");
    }
    value=forw->key;
    temp=forw;
    forw=forw->next;
    temp=NULL;
}



void readmatrix (int sizem)
{
    int i, j;
    for (i=0; i<sizem; i++)
    {
        for (j=0; j<sizem; j++)
        {
            if (i==j)
            {
                adj_matrix[i][j]=0;
            }
            else
            {
                printf ("\nadj_matrix[%d][%d]: ", i, j);
                scanf ("%d", &adj_matrix[i][j]);
                if (adj_matrix[i][j]>1)
                {
                    printf ("\nThe values given for the edges shouldn't be bigger than 1, reinitialize the matrix please!");
                    i=0;
                    j=0;
                }
            }
        }
    }
}

void bfs(int sizem)
{
    int firstn=0;
    int visitednodes [10];
    int i, j;
    for (i=0; i<sizem; i++)
    {
        visitednodes[i]=0;
    }
    if (adj_matrix[0][1]==1)
    {
        visitednodes[firstn]=1;
        printf ("\nNode checked is %d", firstn);
    }
    enqueue(firstn);
    while (last!=NULL)
    {
        dequeue();
        for(j=0; j<sizem; j++)
        {
            if (adj_matrix[value][j]==1 && visitednodes[j]==0)
            {
                visitednodes[j]=1;
                enqueue(j);
                printf ("\nnode visited: %d", j);
            }
            if (adj_matrix[j][value]==1 && visitednodes[j]==0)
            {
                visitednodes[j]=1;
                enqueue(j);
                printf ("\nNode checked is: %d", j);
                j=0;
            }
        }
    }
}

void dfs (int sizem)
{
    int checked[10];
    int i, j, firstn=0;
    for (i=0; i<sizem; i++)
    {
        checked[i]=0;
    }
    if (adj_matrix[0][1]==1)
    {
        checked[firstn]=1;
        printf ("\nNode checked is %d", firstn);
    }
    push(firstn);
    while(forw!=NULL)
    {
        for (j=0; j<sizem; j++)
        {
            if (adj_matrix[value][j]==1 && checked[j]==0)
            {
                checked[j]=1;
                push(j);
                printf ("\nNode checked is: %d", j);
                j=0;
            }
             if (adj_matrix[j][value]==1 && checked[j]==0)
            {
                checked[j]=1;
                push(j);
                printf ("\nNode checked is: %d", j);
                j=0;
            }
        }
      pop();
    }
}


int main()
{
    int sizem, i ,j;
    printf ("Please specify the size of your squarematrix, its maximum size is 10: ");
    scanf ("%d", &sizem);
    while (sizem > 10)
    {
        printf ("\nThe matrix can't be biger than 10, please choose a smaller number");
        scanf ("%d", &sizem);
    }
    readmatrix (sizem);
    for (i=0; i<sizem; i++)
    {
        printf("\n");
        for (j=0; j<sizem; j++)
        {
            printf ("%d ", adj_matrix[i][j]);
        }
    }
    bfs (sizem);
    //dfs(sizem);
    return 0;
}




