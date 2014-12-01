#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

Node *first,*last,*temp,*first1,*top,*top1;

int adj[10][10],info;
char vertices[10];

void enq(int info)
{
    if (last == NULL)
    {
        last = (struct node *)malloc(sizeof(struct node));
        last->next = NULL;
        last->data = info;
        first = last;
    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        last->next = temp;
        temp->data = info;
        temp->next = NULL;

        last = temp;
    }
}

void deq()
{
    first1 = first;

    if (first1 == NULL)
    {
        printf("\nTrying to display elements from empty queue");
        return;
    }
    else
        if (first1->next != NULL)
        {
            first1 = first1->next;
            printf("\n Dequed value : %d", first->data);
            free(first);
            first = first1;
        }
        else
        {
            printf("\n Dequed value : %d", first->data);
            free(first);
            first = NULL;
            last = NULL;
        }
}

void push(int info)
{
    if (top == NULL)
    {
        top =(struct node *)malloc(sizeof(struct node));
        top->next = NULL;
        top->data = info;
    }
    else
    {
        temp =(struct node *)malloc(sizeof(struct node));
        temp->next = top;
        temp->data = info;
        top = temp;
    }
}

void pop()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("\nTrying to pop from empty stack");
        return;
    }
    else
        top1 = top1->next;
        printf("\n Popped value : %d", top->data);
        free(top);
        top = top1;
}

void create_mat(int size)
{
    int i, j;
    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(i == j) adj[i][j] == 0;
            else
            {
                printf("\n Element: [%d][%d]", i, j);
                scanf("%d", &adj[i][j]);                /** ONLY 1 OR 0 VALUES **/
            }
        }
    }
}

void BFS(int size)
{
    int first = 0, checked[10], i,j;
    for(i = 0; i < size; i++)
    {
        checked[i] = 0; /** mark all nodes unvisited **/
    }
    if(adj[0][1] == 1)
    {
        checked[first] == 1;
        printf("\n Checked: %d", first);
    }
    enq(first);
    while(last != NULL)
    {
        deq();
        for(j=0; j<size; j++)
        {
            if (adj[info][j]==1 && checked[j] == 0)
            {
                checked[j] = 1;
                enq(j);
                printf ("\nVisited: %d", j);
            }
        }
    }
}

void DFS(int size)
{
    int checked[10],i,j,first = 0;
    for (i=0; i<size; i++)
    {
        checked[i] = 0; /** mark all nodes as unvisited **/
    }
    if (adj[0][1] == 1)
    {
        checked[first] = 1;
        printf ("\nChecked is %d", first);
    }
    push(first);
    while(top != NULL)
    {
        for (j=0; j<size; j++)
        {
            if (adj[info][j]==1 && checked[j]==0)
            {
                checked[j]=1;
                push(j);
                printf ("\nChecked is: %d", j);
                j=0;
            }
        }
      pop();
    }
}

int main()
{
    int size,i,j;
    printf ("Enter the size of matrix: ");
    scanf ("%d", &size);
    create_mat(size);

    BFS(size);
    DFS(size);
    return 0;
}
