#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
}Node;

Node* createNode(int val)
{
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    p->val=val;
    return p;
}

void freeNode(Node **p)
{
    free(*p);
}

void createQueue(Node **froont, Node**rear)
{
    *froont=NULL;
    *rear=NULL;
}

void showQueue(Node *froont)
{
    Node *p=(Node*)malloc(sizeof(Node));

    if(froont!=NULL)
    {
        p=froont;

        while(p!=NULL)
        {
            printf("%d ",p->val);
            p=p->next;
        }

        printf("\n");
    }

    else
    {
        printf("\nThe queue is empty!\n");
    }
}

void enqueue (Node **froont, Node **rear, Node *p)
{

    if(*froont==NULL)
    {
        *froont=p;
        *rear=p;
    }
    else
    {
        (*rear)->next=p;
        *rear=p;
    }
    p->next=NULL;
}
void dequeue(Node **froont, Node **rear)
{
    Node *p;
    if(*froont==NULL)
    {
        printf("\nThe queue is empty!\n");
    }
    p=*froont;
    *froont=(*froont)->next;
    freeNode(&p);
    if(*froont==NULL)
    {
        *rear=NULL;
        printf("\nThe queue is now empty (the last node was removed).\n");
    }
}

void deleteQueue(Node **froont, Node **rear)
{
    Node *p;
    while(*froont!=NULL)
    {
        p=*froont;
        *froont=(*froont)->next;
        freeNode(&p);
    }
    *rear=NULL;
}

void bfs(int n, int s, int **a)
/** n-> number of nodes
    s-> first node **/
{
    int visited[s],result[n];
    Node *froont, *rear, *p,*q;
    froont=(Node*)malloc(sizeof(Node));
    rear=(Node*)malloc(sizeof(Node));

    int i,j,k=0;
    int v;

    createQueue(&froont,&rear);

    /** no nodes are visited **/
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }

    /** the head of the graph is marked as visited
        and enqueued and put in the result **/
    visited[s]=1;
    p=createNode(s);
    enqueue(&froont,&rear,p);

    result[k]=s;
    k++;

    /** until the queue is empty **/
    while(froont!=NULL)
    {
        /** v is the first elemnt of the queue**/
        v=froont->val;
        dequeue(&froont,&rear);

        /** finds out if v has unvisited neighbours**/
        for(j=0;j<n;j++)
        {
            if(a[v][j]==1)
            {
                if(visited[j]==0)
                {
                    /** adds the unvisited neighbours to the queue **/
                    visited[j]=1;
                    q=createNode(j);
                    enqueue(&froont,&rear,q);
                    result[k]=j;
                    k++;
                }
            }
        }
    }

    /** the result (BFS) **/
    for(i=0;i<k;i++)
        printf("%d  ",result[i]);
}

int main()
{
    int n,j,i;
    scanf("%d",&n);
    int **a=(int**)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    bfs(n,0,a);

    return 0;
}
