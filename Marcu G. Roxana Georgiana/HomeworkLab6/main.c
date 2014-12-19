#include <stdio.h>
#include <stdlib.h>

static char vertices[]="ABCDEFGH";
int v=8;    //nr of vertices
int matrix[9][9];
char resultbfs[9];      //the graph after traversal
char resultdfs[9];

void CreateMatrix()
{
    int i,j;
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            matrix[i][j]=0;
    matrix[0][1]=matrix[1][0]=1;
    matrix[0][3]=matrix[3][0]=1;
    matrix[0][6]=matrix[6][0]=1;
    matrix[1][4]=matrix[4][1]=1;
    matrix[1][5]=matrix[5][1]=1;
    matrix[2][5]=matrix[5][2]=1;
    matrix[2][7]=matrix[7][2]=1;
    matrix[3][5]=matrix[5][3]=1;
    matrix[4][6]=matrix[6][4]=1;
}

void PrintMatrix()
{
    int i,j;
    printf("  ");
    for(i=0;i<=v;i++)
        printf(" %c",vertices[i]);
    printf("\n");

    for(i=0;i<v;i++)
    {  printf("%c ",vertices[i]);
         for(j=0;j<v;j++)
            printf(" %d",matrix[i][j]);
        printf("\n");
    }
}

typedef struct queue
{
    int value;
    struct queue *next;
}QueueN;
QueueN *head, *last;

void enqueue(int content)
{
    if(head==NULL)
    {
        head=(QueueN*)malloc(sizeof(QueueN));
        head->value=content;
        head->next=NULL;
    }
    else
        if(last==NULL)
        {
            last = (QueueN*)malloc(sizeof(QueueN));
            last->value= content;
            head->next = last;
            last->next=NULL;
        }
        else
        {
            QueueN *node = (QueueN*) malloc(sizeof(QueueN));
            node->value= content;
            node->next = NULL;
            last->next = node;
            last = node;
        }
}

int dequeue()
{
    if(head!=NULL)
    {
        int item=head->value;
        head = head->next;
        return item;
    }
    else
        printf("The queue is empty\n");
}

void bfs(int node)
{
    int mark[v];        // 1=visited, 0=unvisited
    int i,j;

    for(i=0;i<v;i++)
        mark[i]=0;

    mark[node]=1;       //the first vertex -A- is visited  (node=0)
    resultbfs[0]=vertices[node];
    int count=1;        //the position for resultbfs

    for(j=node+1;j<v;j++)       //i begun from the second position -node+1- because there isn't an edge between 0 and 0
        if(matrix[node][j]==1)  //if there exists an edge between node and j
            {   enqueue(j);     //vertex j is enqueued
                mark[j]=1;
                resultbfs[count]=vertices[j];
                count++;
            }

    while(head!=NULL)
    {
        int vertex=dequeue();       //holds the vertex for which i search the adjacent vertices

        for(j=0;j<v;j++)
            if(matrix[vertex][j]==1)
                if(mark[j]==0)      //only if vertex j wasn't marked before
                {
                    enqueue(j);
                    mark[j]=1;
                    resultbfs[count]=vertices[j];
                    count++;
                }
    }
    resultbfs[count]='\0';
}

typedef struct stack
{
    int value;
    struct stack *next;
}StackN;
StackN *top;

void push(int content)
{
    StackN *node=(StackN*)malloc(sizeof(StackN));
    node->value=content;
    if(top==NULL)
    {
        top=node;
        top->next=NULL;
    }
    else
    {
        node->next=top;
        top=node;
    }
}

int pop()
{
    int item;
    if(top!=NULL)
    {
        item=top->value;
        top=top->next;
        return item;
    }
    else
        printf("Stack is empty\n");
}

void dfs(int node)
{
    int i,j;
    int mark[v];

    for(i=0;i<v;i++)
        mark[i]=0;

    mark[node]=1;
    push(node);         //the first vertex -A- is pushed in the stack
    resultdfs[0]=vertices[node];
    int count=1;

    i=node;
    while(i<v)      //the longest simple path from the first vertex is pushed
    {
        j=i+1;
        while(matrix[i][j]==0 && j<v)
            j++;
        if(matrix[i][j]==1 && j<v && mark[j]==0)
            {
                mark[j]=1;
                push(j);
                resultdfs[count]=vertices[j];
                count++;
            }
        i=j;        //the graph is depth-first traversed
    }

    while(top!=NULL)
    {
        int vertex=top->value;      //the searching begins from the value of the top
        i=vertex;
        while(i<v)      //i looked for the next adjacent vertex which isn't marked
        {
            j=0;
                    while( (matrix[i][j]==0 && j<v) || (matrix[i][j]==1 && j<v && mark[j]==1))
                        j++;
                    if(matrix[i][j]==1 && j<v && mark[j]==0)
                    {
                        mark[j]=1;
                        push(j);
                        resultdfs[count]=vertices[j];
                        count++;
                    }
            i=j;
        }
        if(i>=v)
            pop();
    }
    resultdfs[count]='\0';
}
int main()
{
    CreateMatrix();
    printf("The adjacency matrix is:\n");
    PrintMatrix();

    int i;

    bfs(0);
    printf("\nThe breadth-first traversal of the graph is:\n");
    for(i=0;i<v;i++)
    {
        printf("%c ",resultbfs[i]);
    }
    printf("\n");

    dfs(0);
    printf("\nThe depth-first traversal of the graph is:\n");
    for(i=0;i<v;i++)
    {
        printf("%c ",resultdfs[i]);
    }
    printf("\n");

    return 0;
}
