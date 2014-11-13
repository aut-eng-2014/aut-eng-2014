#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node* next;
} NodeT;
NodeT *first, *last, *var;


void init()
{
    first=(NodeT*)malloc(sizeof(NodeT));
    last=(NodeT*)malloc(sizeof(NodeT));
    first->value=10;
    first->next=last;
    last->value=6;
    last->next=NULL;
}


void transversal()
{
    NodeT *var=first;
    while (var!=NULL)
        var=var->next;

}


void addlast(int value)
{
    NodeT *newN=(NodeT*)malloc(sizeof(NodeT));
    newN->value=value;
    newN->next=NULL;
    last->next=newN;
    last=last->next;
}
NodeT *finde(int value)
{
    NodeT *varF;
    varF=first;
    while (varF!=NULL)
        if((varF->value==value))
            return varF;
        else
            varF=varF->next ;
    return NULL;
}


void addfirst(int value)
{
    NodeT *newN=(NodeT*)malloc(sizeof(NodeT));
    newN->value=value;
    newN->next=first;
    first=newN;
}
void afisare()
{
    NodeT *var;
    var=first;
    while(var!=NULL)
    {
        printf("%d ", var->value);
        var=var->next;
    }
    printf("\n");
}


void stergere(int value)
{
    NodeT *q, *q1;
    q1=NULL;
    q=first ;
    while (q!=NULL)
    {
        if(q->value==value) break;
        q1=q;
        q=q->next;

    }
    if(q!=NULL)
    {
        if(q==first)
        {
            first= first->next;
            free(q) ;
            if(first==NULL) last=NULL;
        }
        else
        {
            q1->next=q->next;
            if(q==last) last=q1;
            free(q) ;
        }
    }
}

void numarare()
{
    struct node *var;
    int length=0;
    var=first;
    while(var!=NULL)
    {
        length++;
        var=var->next;
    }
printf("Length of linked List: %d",length);
}


void sortin()
{
    NodeT* var=first;
    int newS;
    int OK=0;
    while(OK==0)
    {
        OK=1;
        var=first;
        while(var->next!=NULL)
        {
            if(var->value > var->next->value)
            {
                newS = var->value;
                var->value = var->next->value;
                var->next->value = newS;
                OK=0;
            }
            var=var->next;
        }
    }
}

int main()
{
    init();
    transversal();
    addfirst(31);
    addlast(2);
    afisare();
    stergere(31);
    afisare();
    NodeT *b=finde(10);
    if(b!=NULL)
        printf("%d",b->value);
    else
        printf("Value not found");
    printf("\n");
    numarare();
    printf("\n");
    sortin();
    afisare();
    return 0;
}
