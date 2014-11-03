#include <stdio.h>
#include <stdlib.h>
//Doubly-linked list-Implementation
typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head; //global variable-pointer to head node

struct Node* GetNewNode(int x)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;//link to the next node
    newNode->prev=NULL;//link to the previous node
    return newNode;
};


void Insertathead(int x)
{
    struct Node* newNode=GetNewNode(x);
    if(head==NULL)
    {
        head=newNode;//list could be empty so head will be equall to null
        return;
    }
    else
    {
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }
}

void InsertatEnd(int x)
{
    struct Node *temp1,*temp2=head;
    //in case of empty list
    if(head==NULL)
    {
        head =(struct Node *)malloc(sizeof(struct Node));
        head->prev=NULL;
        head->data=x;
        head->next=NULL;
    }
    else
    {
        //traverse at the end
        while(temp2->next!=NULL)
            temp2=temp2->next;
        //add node at the end
        temp1=(struct Node*)malloc(sizeof(struct Node));
        temp1->data=x;
        temp1->next=NULL;
        temp1->prev=temp2;
        temp2->next=temp1;
    }
}
void Delete(int x)
{
    struct Node *temp=head;
    //traverse
    while(temp!=NULL)
    {
        //node found which matches the deletion criteria
        if(temp->data==x)
        {
            //first node
            if(temp==head)
            {
                head=head->next;
                head->prev=NULL;
            }
            else
            {
                //last node
                if(temp->next==NULL)
                    temp->prev->next=NULL;
                else
                    //anything between
                {
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                }
            }
            free(temp);
            return;
        }
        temp=temp->next;//until the node is found
    }
    printf("%d not found",x);
}
void Print()
{
    struct Node *temp=head;
    printf("Forward: ");
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("/n");
}

void PrintReverse()
{
    struct Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->prev;
    }
    printf("/n");
}

int serc(struct Node *head, int key)
{
    head = head -> next;
    //search in the linked list for the key
    while(head!=NULL)
    {
        if(head->data == key)
        {
            return 1;
        }
        head = head -> next;
    }
    return 0;
}

int main()
{
    head=NULL;//Empty list
    InsertatEnd(5);
    Print();
    InsertatEnd(10);
    Print();
    return 0;
}


