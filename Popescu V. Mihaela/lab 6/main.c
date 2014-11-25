#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev, *next;
} NodeT;

NodeT *first, *last;//used for the queue
NodeT *f, *l;//used for the stec

void init_queue()
{
    //FIFO
    //a queue is a doubly linked list which adds elements at the beginning of the list and removes from the end of the list
    first=(NodeT*)malloc(sizeof(NodeT));
    last=(NodeT*)malloc(sizeof(NodeT));
    first->data=-1;
    last->data=-1;
    first->next=last;
    first->prev=NULL;
    last->prev=first;
    last->next=NULL;
}

void enqueue(int val)
{
    NodeT *newN;
    newN=(NodeT*)malloc(sizeof(NodeT));
    newN->data=val;
    newN->prev=NULL;
    newN->next=first;
    first->prev=newN;
    first=newN;
}

int dequeue()
{
    NodeT *tmp, *val;
    val=last;
    tmp=(NodeT*)malloc(sizeof(NodeT));
    tmp=last->prev;
    free(last);
    last=tmp;
    last->next=NULL;
    return val->data;
}

void init_stec()
{
    //LIFO
    //the stec is a doubly linked list to which you can add or remove elements only from the beginning of the list
    f=(NodeT*)malloc(sizeof(NodeT));
    l=(NodeT*)malloc(sizeof(NodeT));
    f->data=-1;
    l->data=-1;
    f->next=l;
    f->prev=NULL;
    l->prev=f;
    l->next=NULL;
}

void push(int val)//insert the element "val"
{
    NodeT *newN;
    newN=(NodeT*)malloc(sizeof(NodeT));
    newN->data=val;
    newN->prev=NULL;
    newN->next=f;
    f->prev=newN;
    f=newN;
}

void pop()
{
    NodeT *tmp;
    tmp=(NodeT*)malloc(sizeof(NodeT));
    tmp=f->next;
    free(f);
    f=tmp;
}

void show_queue(NodeT *p)
{
    if(p->data==0)
    {
        printf("There are no elements in the queue.");
        return;
    }
    while(p!=NULL)
    {
        printf("%d\n", p->data);
        p=p->next;
    }
    return;
}

void show_stec(NodeT *p)
{
    if(p==NULL)
    {
        printf("There are no elements in the stec.");
        return;
    }
    while(p!=NULL)
    {
        printf("%d\n", p->data);
        p=p->next;
    }
    return;
}

int **mat;
int** read_square_matrix(int n)
{
    int i,j;
    mat=(int**)malloc(n* sizeof(int*)); //dinamic memory allocation
    for (i=0; i<n; i++)
        mat[i] = (int*)malloc(n * sizeof(int));
    for(i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            printf("m[%d][%d]=",i,j );
            scanf("%d", &mat[i][j]);
        }
    return **mat;
}

void bfs(int nr_of_nodes, int first_node)
{
    int matrix[nr_of_nodes][nr_of_nodes];
    int visited [nr_of_nodes];
    int i, v, w;
    init_queue();
    **matrix=read_square_matrix(nr_of_nodes);
    for(i=0; i<nr_of_nodes; i++)
        visited[i]=0;//mark nodes as unvisited=0
    visited[first_node]=1;//mark first node as visited=1
    enqueue(first_node);
    printf("%d ", first_node);
    while (first->data!=-1)//WHILE the queue!=NULL
    {
        v=dequeue();
        for(w=0; w<nr_of_nodes; w++)
            if (matrix[v][w]==1 && visited[w]==0)
            {
                visited[w]=1;
                enqueue(w);
                printf("%d ", w);
            }
    }
}

void dfs(int nr_of_nodes, int first_node)
{
    int matrix[nr_of_nodes][nr_of_nodes];
    int visited [nr_of_nodes];
    int i, v, w, g;// v, w are nodes
    init_stec();
    **matrix=read_square_matrix(nr_of_nodes);
    for(i=0; i<nr_of_nodes; i++)
        visited[i]=0;//mark nodes as unvisited=0
    visited[first_node]=1;//mark first node as visited=1
    push(first_node);
    printf("%d ", first_node);
    while (f->data!=-1)
    {
        v=f->data; //the first element of the stack, i.e., the top
        g=0;
        for(w=0; w<nr_of_nodes && g==0; w++)
            if (matrix[v][w]==1 && visited[w]==0)
            {
                g=1;
                visited[w]=1;
                push(w);
                printf("%d ", w);
            }
        if (g==0)
            pop();
    }
}

int main()
{
    char ch;
    int n, f;
    printf("b.BFS d.DFS q.Quit\n");
    while (ch!='q')
    {
        scanf("%c", &ch);
        switch (ch)
        {
        case 'b':
            printf("Number of nodes: \n");
            scanf("%d%*c", &n);
            printf("Search after node: \n");
            scanf("%d%*c", &f);
            bfs(n, f);
            break;
        case 'd':
            printf("Number of nodes: \n");
            scanf("%d%*c", &n);
            printf("Search after node: \n");
            scanf("%d%*c", &f);
            dfs(n,f);
            break;
        case 'q':
            return 0;
            break;
        default:
            scanf("%*c");
            printf("Press a valid key (b, d, q).\n");
            break;
        }
        printf("b.BFS d.DFS q.Quit\n");
    }
    return 0;
}
