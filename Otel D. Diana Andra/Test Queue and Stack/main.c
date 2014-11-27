#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Queue
 {
        int value;
        struct Queue* next;
 }*first, *last;

void deQ()
{
       struct Queue *temp=last;
      if(temp==last)
      {
             last=last->next;
             free(temp);
      }
      else
      printf("The queue is empty.\n");
}

void enQ(int val)
{
     struct Queue *temp=(struct Queue*)malloc(sizeof(struct Queue));
     temp->value=val;
     if (first==NULL)
     {
           first=temp;
           first->next=NULL;
           last=first;
     }
     else
     {
           first->next=temp;
           first=temp;
           first->next=NULL;
     }
}

void display()
{
     struct Queue *temp=last;
     if(temp!=NULL)
     {
           printf("\nThe queue is: ");
           while(temp!=NULL)
           {
                printf("\t%d", temp->value);
                temp=temp->next;
           }
     printf("\n");
     }
     else
     printf("\nThe queue is empty.");
}

void push(int val)
{
     struct Queue *temp=(struct Queue*)malloc(sizeof(struct Queue));
     temp->value=val;
     temp->next=first;
     first=temp;
}

void pop()
{
      struct Queue *temp=first;
      if(first==NULL)
      {
             first=first->next;
             free(temp);
      }
      else
      printf("The queue is empty.\n");
}


int main()
{
     int i=0;
     first=NULL;
     printf("1. Enqueue\n");
     printf("2. Dequeue\n");
     printf("3. Display queue\n");
     printf("4. Exit\n");
     while(1)
     {
          printf(" \nChoose operation from above: ");
          scanf("%d",&i);
          switch(i)
          {
                case 1:
                {
                     int val;
                     printf("\nPush the value: ");
                     scanf("%d",&val);
                     enQ(val);
                     display();
                     break;
                }
                case 2:
                {
                     deQ();
                     display();
                     break;
                }
                case 3:
                {
                     display();
                     break;
                }
                case 4:
                {
                     exit(0);
                }
                default:
                {
                     printf("\nOperation does not exist.");
                }
          }
     }
}
