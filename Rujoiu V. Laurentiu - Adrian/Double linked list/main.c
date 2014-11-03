#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next, *prev;
} Node;

Node *start, *finish;

void init()
{
    start = (Node*)malloc(sizeof(Node));
    finish = (Node*)malloc(sizeof(Node));
    //intermediate = (Node*)malloc(sizeof(Node));

    printf("Enter the first node: ");
    scanf("%d", &start->data);
    printf("Enter the last node: ");
    scanf("%d", &finish->data);

    start->prev = NULL;
    start->next = finish;
    finish->prev = start;
    finish->next = NULL;
}

void addFirst()
{
    Node *firstN;
    firstN = (Node*)malloc(sizeof(Node));
    printf("Enter the node you want to add first: ");
    scanf("%d", &firstN->data);

    firstN->next = start;
    start->prev = firstN;
    firstN->prev = NULL;
    start = firstN;
}

void addLast()
{
    Node *lastN;
    lastN = (Node*)malloc(sizeof(Node));
    printf("Enter the node you want to add last: ");
    scanf("%d", &lastN->data);

    finish->next = lastN;
    lastN->prev = finish;
    lastN->next = NULL;
    finish = lastN;
}
void traverse()
{
    Node *traverse = (Node*)malloc(sizeof(Node));
    traverse = start;
    while(traverse != NULL)
    {
        printf("%d\n", traverse->data);
        traverse = traverse->next;
    }
}

void removeN()
{
    int val;
    printf("Enter the value of the node you want to remove: ");
    scanf("%d", &val);

    Node *counter = (Node*)malloc(sizeof(Node));
    Node *temp = (Node*)malloc(sizeof(Node));
    temp = 0;
    counter = start;
    while(counter == 0)
    {
        if(counter->data == val)
        {
            break;
            temp = counter;
                   counter = counter->next;
        }
        if(counter != 0)
        {
            if(counter != start)
            {
                temp->next = counter->next;
                if(counter == finish)
                {
                    finish = temp;
                    free(counter);
                }

            }
        }
    }
}

void countN()
{
    int i = 0;
    Node *counter = (Node*)malloc(sizeof(Node));
    counter = start;

    while(counter != NULL)
    {
        counter = counter->next;
        i++;
    }
    printf("The number of elements is %d\n", i);
}

void swapN(Node *start, Node *finish)
{
    Node *temp = (Node*)malloc(sizeof(Node));
    temp = start->data;
    start->data = finish->data;
    finish->data = temp;
}

void sortN(Node *temp)
{
    int counter = 0;
    for(counter = 0; counter < 4; counter++)
    {
        if(temp->data > temp->next->data){
        }
        else swapN(temp, temp->next);
        temp = temp->next;
    }
}


int main()
{
    Node *temp;
    Node *swapper = (Node*)malloc(sizeof(Node));
    temp = swapper;
    temp->next = NULL;
    temp->prev = NULL;

    init();
    addFirst();
    addLast();
    removeN();
    countN();
    traverse();
    sortN(swapper);

    return 0;
}
