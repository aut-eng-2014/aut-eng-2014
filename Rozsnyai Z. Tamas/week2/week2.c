/*
Add -first/last
remove
search
sort-asc/desc
count
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


typedef struct bidirectional
{
    struct bidirectional *next;
    struct bidirectional *prev;
    int key;
}listNode;

    listNode *First, *Last;
    int enr;


void defFirstLast()
{
    First=(listNode*)malloc(sizeof(listNode));
    Last=(listNode*)malloc(sizeof(listNode));
    First->prev=NULL;
    Last->next=NULL;
    First->next=Last;
    Last->prev=First;
    enr=0;
    printf("Your first element:");
    int x;
    scanf("%d",&x);
    First->key=x;
    enr++;
    printf("Your last element:");
    scanf("%d", &x);
    Last->key=x;
    enr++;

}

void AddFirst(int x)
{


    listNode *p;
    p=(listNode*)malloc(sizeof(listNode));
    p->next=First;
    First->prev=p;
    p->prev=NULL;
    p->key=x;
    First=p;
    //free(p);
    enr++;

}

void AddLast(int x)
{
    listNode *p;
    p=(listNode*)malloc(sizeof(listNode));
    p->prev=Last;
    Last->next=p;
    p->next=NULL;
    p->key=x;
    Last=p;
    //free(p);
    enr++;
}

int menu()
{
    system("cls");
    printf("--------------------------\n");
    printf("|  MENU                  |\n");
    printf("--------------------------\n");
    printf("| 0). The list           |\n");
    printf("| 1). New element        |\n");
    printf("| 2). Remove element     |\n");
    printf("| 3). Search for number  |\n");
    printf("| 4). Sort the list      |\n");
    printf("| 5). Count              |\n");
    printf("| 6). Exit               |\n");
    printf("--------------------------\n");
    printf("| NR. of elements:%d      |\n",enr);
    printf("--------------------------\n");
    printf("Chose a menu point:");
    int x;
    scanf("%d",&x);
    return x;
}

void sort_bb()
{
    system("cls");
    listNode *tempF, *tempL;
    int x;
    tempF=First;

    while (tempF!=Last)
    {
        tempL=Last;
        while (tempL!=tempF)
        {
            if (tempL->key<tempF->key)
            {
                x=tempF->key;
                tempF->key=tempL->key;
                tempL->key=x;
            }
            tempL=tempL->prev;
        }
        tempF=tempF->next;
    }
}

int count()
{
    int x=0;
    listNode *temp=First;
    while (temp!=NULL)
    {
        x++;
        temp=temp->next;
    }
    return x;
}

int search(int x)
{
    listNode *temp=First;
    while (temp!=NULL)
    {
        if (temp->key==x)
        {
            return temp;
        }
        temp=temp->next;
    }
    return 0;
}

void listout()
{
    listNode *p;
    p=First;
    printf("The list:");
    while(p!=NULL)
    {

        printf("%d ",p->key);

        p=p->next;

    }

}

int main()
{
    system("cls");
    defFirstLast();
    listNode *p,*q;
    p=(listNode*)malloc(sizeof(listNode));
    q=(listNode*)malloc(sizeof(listNode));
    int menupoint=9,x,y;
    char key='p';
    char m1[1];
    while (menupoint!=6)
    {
        menupoint=menu();
        switch (menupoint)
        {
        case 0:
        {
            listout();
            printf("\n Press any key!");

            key=getch();
            break;
        }
        case 1:
        {
            menu1:
            system("cls");
            printf("Insert element to the <t> Top or <b> Bottom:");
            scanf(" %c",m1);


            if ((m1[0]=='T')||(m1[0]=='t'))
            {
                printf("The new element: ");
                scanf(" %d",&x);
                AddFirst(x);
            }
            else
            {
                if ((m1[0]=='b')||(m1[0]=='B'))
                {
                    printf("The new element: ");
                    scanf(" %d",&x);
                    AddLast(x);
                }
                else
                {
                    goto menu1;
                }
            }
        break;
        }
        case 2:
        {

            p=First;
            while ((key!='R')&&(p!=0))
            {
                system("cls");
                printf("<Space> for next <R> for Remove:\n");
                printf("< %d >\n",p->key);

                key=getch();
                if ((key=='R')||(key=='r'))
                {
                    q=p->prev;
                    q->next=p->next;
                    q=q->next;
                    q->prev=p->prev;
                    system("cls");
                    printf("Removed!");
                    free(p);
                    enr--;
                    key='R';
                }
                else
                {
                    p=p->next;
                }

            }
        break;
        }
        case 3:
        {
            printf("Number:");
            scanf("%d",&x);
            y=search(x);
            if (y==0)
            {
                printf("No %d in the list!\n Press any key!",x);
            }
            else
            {
            printf("The nr:%d is stored at the adress:%d\n Press any key!",x,y);
            }
            key=getch();
            break;
        }
        case 4:
        {
            sort_bb();
            break;
        }
        case 5:
        {
            x=count();
            printf("Nr. of elements:%d\n Press any key!",x);
            key=getch();
            enr=x;
        break;
        }
        }
    }


}
