#include<stdio.h>
#include<stdlib.h>

#define MAXN 100 /* max nr of nodes */

/* STACK type definition */
typedef struct Node
{
    int data;
    struct Node* link;
} NodeT;

NodeT* top=NULL;

void Push(int x)
{
    NodeT* temp=(NodeT*)malloc(sizeof(NodeT*));
    temp->data=x;
    temp->link=top;
    top=temp;
}

void Pop()
{
    NodeT* temp;
    if (top == NULL)
    {
        printf("The stack is empty\n");
        return;
    }
    temp=top;
    top=top->link;
    free(temp);
}

int Top()
{
    NodeT* temp;
    if (top == NULL)
    {
        printf("The stack is empty, nothing to Top\n");
        return;
    }
    temp=top;
    return temp->data;
}

/* QUEUE type definition */
/* Note: i am using the same type definition (NodeT) as for the stack */

NodeT *front=NULL, *rear=NULL;

void enqueue(int x)
{
    NodeT* temp=(NodeT*)malloc(sizeof(NodeT*));
    temp->data=x;
    temp->link=NULL;

    if(front == NULL && rear == NULL)
    {
		front = rear = temp;
		return;
	}
	rear->link = temp;
	rear = temp;
}

void dequeue()
{
	NodeT* temp = front;
	if(front == NULL)
    {
		printf("Queue is Empty\n");
		return;
    }

	if(front == rear)
		front = rear = NULL;
	else
		front = front->link;
	free(temp);
}

/*  un-directed graph type implementation, using adjacency lists
    represented as fixed-length arrays */

/*  the GRAPH type definitions */
/*  a structure to represent a node from the adjacency list */
typedef struct node
{
    int vertex;
    struct node *next;
} node;

node *G[MAXN];    /* heads of the linked list */
int visited[MAXN];


void addEdge(int i,int j)
{
    node *newNode;
    //acquire memory for the new node
    newNode=(node*)malloc(sizeof(node));
    newNode->vertex=j;
    newNode->next=NULL;

    /* insert the node in the linked list number i */
    if( G[i]==NULL ) /* there are no other nodes insertec */
        {
            G[i]=newNode;
        }
    else /*go to the end of the list and insert it there. O(n) */
    {
        node *temp=G[i];
        while(temp->next != NULL)
            temp=temp->next;
        temp->next=newNode;
    }
}

void printGraph(int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%d: ", i);
        node *p=G[i];
        while (p != NULL)
        {
            printf("%d ", p->vertex);
            p=p->next;
        }
        printf("\n");
    }
}

void DFS(int i)
{
    node *p;
    printf("%d ",i);
    p=G[i];
    visited[i]=1;

    while(p!=NULL)
    {
        i=p->vertex;
        if(!visited[i])
            DFS(i);
        p=p->next;
    }
}

void DFSnonrec(int i)
{
    node *p;
    Push(i);
    visited[i]=1;
    printf("%d ", i);

    int k=0;

    while (top != NULL)
    {
       if (k==0) p=G[Top()];
       if (visited[p->vertex] == 0)
       {
           Push(p->vertex);
           visited[p->vertex]=1;
           printf("%d ", p->vertex);
           k=0;

       }
       else
       {
           p=p->next;
           k=1;
       }
        if (p==NULL)
        {
            Pop();
            k=0;
        }
    }

}

void BFS(int i)
{
    printf("%d ", i);
    visited[i]=1;
    enqueue(i);
    node *p=G[front->data];

   while (front != NULL )
   {
        p=G[front->data];
        dequeue();

        while (p!=NULL)
        {
            if (visited[p->vertex]==0)
            {
                printf("%d ", p->vertex);
                visited[p->vertex]=1;
                enqueue(p->vertex);
            }
            p=p->next;
        }
   }

}

void initVisited(int nr)
{
    int i;
    for(i=0; i<nr; i++)
        visited[i]=0;
}

int main()
{
    FILE *pf;
    pf=fopen("graph.txt", "r");
    /* reads the graph adj matrix from file and turns it into an adj list */
    /* this is how the file should look like:

                4
                0 1 1 0
                1 0 1 0
                1 1 0 1
                0 0 1 0

        first line=nr of vertices
    */
    if (pf != NULL)
    {
        int V,i;
        fscanf(pf,"%d\n", &V);
         //initialise G[] with a null
        for (i=0; i<V; i++)
            G[i]=NULL;

        int j,val;
        for (i=0; i<V; i++)
            for (j=0; j<V; j++)
                {
                    fscanf(pf,"%d", &val);
                    if (val==1)
                        addEdge(i,j);
                }
        printGraph(V);

        /* before dfs or bfs all nodes must be marked as NOT visited */
        initVisited(V);
        printf("DFS: ");
        DFS(0);

        initVisited(V);
        printf("\nDFS: ");
        DFSnonrec(0);
        printf(" (nonrecursive)");

        initVisited(V);
        printf("\nBFS: ");
        BFS(0);

    }
    else
        printf("file can't be opened / file not found / return\n");


    return 0;
}
