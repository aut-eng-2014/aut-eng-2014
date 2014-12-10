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

void createStack(Node **top, Node**bottom)
{
    *top=NULL;
    *bottom=NULL;
}

void showStack(Node *top)
{
    Node *p=(Node*)malloc(sizeof(Node));

    if(top!=NULL)
    {
        p=top;

        while(p!=NULL)
        {
            printf("%d ",p->val);
            p=p->next;
        }

        printf("\n");
    }

    else
    {
        printf("\nThe stack is empty!\n");
    }
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
        printf("\nThe stack is now empty (the last node was removed).\n");
    }
}
void deleteStack(Node **top, Node **bottom)
{
    Node *p;
    while(*top!=NULL)
    {
        p=*top;
        *top=(*top)->next;
        freeNode(&p);
    }
    *bottom=NULL;
}

void dfs(int n, int s, int **a)
/** n-> number of nodes
    s-> first node **/
{
    int visited[s],result[n];
    Node *top, *bottom, *p,*q;
    top=(Node*)malloc(sizeof(Node));
    bottom=(Node*)malloc(sizeof(Node));

    int i,j,k=0;
    int ok;
    int v;

    createStack(&top,&bottom);

    /** no nodes are visited **/
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }

    /** the head of the graph is marked as visited
        and pushed in the stack and in the result **/
    visited[s]=1;
    p=createNode(s);
    push(&top,&bottom,p);

    result[k]=s;
    k++;


    /** until the stack is empty **/
    while(top!=NULL)
    {
        /** v is the top of the stack **/
        v=top->val;

        j=0;

        /** ok=1 if is found an unvisited neighbour of v
            ok=0 if all neighbours of v are visited **/
        ok=0;

        /** finds out if v has unvisited neighbours**/
        while(j<n && ok==0)
        {
            if(a[v][j]==1 && visited[j]==0)
            {
                ok=1;
            }
            j++;
        }
        /** if v has only visited neighbours
            pop v from the stack **/
        if(ok==0)
        {
            pop(&top,&bottom);

        }
        /** unvisited neighbour found
            push it in the stack **/
        else
        {
            visited[j-1]=1;
            q=createNode(j-1);
            push(&top,&bottom,q);

            /** the node is added in the result string **/
            result[k]=j-1;
            k++;
        }
    }

    /** the result (DFS) **/
    for(i=0;i<n;i++)
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

    dfs(n,0,a);

    return 0;
}
