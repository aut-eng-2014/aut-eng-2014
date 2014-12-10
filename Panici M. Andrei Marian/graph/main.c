#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;
} Node;

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
        printf("\nThe queue is now empty the last node was deleted\n");
    }
}

void bfs(int n, int s, int **a)
{
    int visited[s],result[n];
    Node *froont, *rear, *p,*q;
    froont=(Node*)malloc(sizeof(Node));
    rear=(Node*)malloc(sizeof(Node));
    int i,j,k=0;
    int v;
    createQueue(&froont,&rear);
    for(i=0; i<n; i++)
    {
        visited[i]=0;
    }
    visited[s]=1;
    p=createNode(s);
    enqueue(&froont,&rear,p);
    result[k]=s;
    k++;
    while(froont!=NULL)
    {
        v=froont->val;
        dequeue(&froont,&rear);
        for(j=0; j<n; j++)
        {
            if(a[v][j]==1)
            {
                if(visited[j]==0)
                {

                    visited[j]=1;
                    q=createNode(j);
                    enqueue(&froont,&rear,q);
                    result[k]=j;
                    k++;
                }
            }
        }
    }
    for(i=0; i<k; i++)
        printf("%d  ",result[i]);
}

void createStack(Node **top, Node**bottom)
{
    *top=NULL;
    *bottom=NULL;
}

void push(Node **top, Node **bottom, Node *p)
{
    if(*top==NULL)
    {
        *top=p;
        *bottom=p;
        (*bottom)->next=NULL;
    }
    else
    {
        p->next=*top;
        *top=p;
    }
}

void pop(Node **top, Node **bottom)
{
    Node *p;
    if(*top==NULL)
    {
        printf("\n The stack is empty!\n");
        return;
    }
    p=*top;
    *top=(*top)->next;
    freeNode(&p);
    if(*top==NULL)
    {
        *bottom=NULL;
        printf("\nThe stack is now empty the last node was deleted\n");
    }
}

void dfs(int n, int s, int **a)
{
    int visited[s],result[n];
    Node *top, *bottom, *p,*q;
    top=(Node*)malloc(sizeof(Node));
    bottom=(Node*)malloc(sizeof(Node));
    int i,j,k=0;
    int ok;
    int v;
    createStack(&top,&bottom);
    for(i=0; i<n; i++)
    {
        visited[i]=0;
    }
    visited[s]=1;
    p=createNode(s);
    push(&top,&bottom,p);
    result[k]=s;
    k++;
    while(top!=NULL)
    {
        v=top->val;
        j=0;
        ok=0;
        while(j<n && ok==0)
        {
            if(a[v][j]==1 && visited[j]==0)
            {
                ok=1;
            }
            j++;
        }
        if(ok==0)
        {
            pop(&top,&bottom);
        }
        else
        {
            visited[j-1]=1;
            q=createNode(j-1);
            push(&top,&bottom,q);
            result[k]=j-1;
            k++;
        }
    }
    for(i=0; i<n; i++)
        printf("%d  ",result[i]);
}

int main()
{
    int n,j,i;
    scanf("%d",&n);
    int **a=(int**)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    bfs(n,0,a);
    dfs(n,0,a);
    return 0;
}
