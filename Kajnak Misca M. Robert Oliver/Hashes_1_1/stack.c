#include "stack.h"

char sInsert(stac** first,stac** last, char *value)
{
    if ((*first)->val==NULL)
    {
        (*first)->val=value;
        return 0;
    }

    stac * t1=*first,*t2;
    while (t1!=NULL)
    {
        if (!strcmp(t1->val,value))
            return 1;
        t2=t1;
        t1=t1->next;
    }
    t1=(stac*)malloc(sizeof(stac));
    if (t1==NULL)
        return 2;
    *last=t1;
    t1->val=value;
    t1->next=NULL;
    t2->next=t1;

    return 0;
}

void sInsertFast(stac** last, char *value)
{
    if ((*last)->val!=NULL)///it means that the last element is not the first
    {
        (*last)->next=(stac*)malloc(sizeof(stac));
        (*last)=(*last)->next;
        (*last)->next=NULL;
    }
    (*last)->val=value;
}


int sCheck(stac *first,char *value)
{
    if (first->val==NULL)
        return 0;

    while ((first!=NULL) && strcmp(first->val,value)!=0)
    {
        first=first->next;///first will not change outside of this function, a ** is needed for that
    }
    if (first==NULL)
        return 0;
    else
        return strlen(first->val);
}

int sLength(stac *first)
{
    if (first->val==NULL)
        return 0;
    int n=0;
    while (first!=NULL)
    {
        n++;
        first=first->next;
    }
    return n;
}

void sRemoveDuplicates(stac * first,stac ** last)
{
    if ((first->val==NULL) || (first->next==NULL))///if there is only 1 element, it's obviously not a duplicate
        return;
    stac * t1=first,*t2,*t2t;
    while (t1->next!=NULL)
    {
        t2=t1->next;
        t2t=t1;
        while (t2!=NULL)
        {
            if (strcmp(t2->val,t1->val)==0)
            {
                t2t->next=t2->next;
                stac * t3=t2;
                t2=t2t;
                free(t3);
            }
            if (t2!=NULL)
            {
                t2t=t2;
                t2=t2->next;
            }
        }
        if (t1->next!=NULL)
            t1=t1->next;
    }
    *last=t1;
}

char sRemove(stac ** first,char *value)
{
    if ((*first)->val==NULL)
        return 0;

    if (!strcmp((*first)->val,value))
    {
        if ((*first)->next==NULL)
        {
            free(*first);
            *first=(stac*)malloc(sizeof(stac));/***/
            (*first)->val=NULL;///coincides whit init funciton from hash.h
        }
        else
        {
            stac * t=(*first)->next;
            free(*first);
            *first=t;
        }
        return 1;
    }

    stac * t1=(*first)->next,*t2=*first;
    while ((t1!=NULL) && (strcmp(t1->val,value)!=0))
    {
        t2=t1;
        t1=t1->next;
    }
    if (t1==NULL)///a pointer comparison is faster than a string comparison
        return 0;

    t2->next=t1->next;
    free(t1);
    return 1;
}

void sWipe(stac **first)
{
    stac *t=NULL;
    if ((*first)->val==NULL)///first will never be NULL
        return;

    while (*first!=NULL)
    {
        t=*first;
        *first=(*first)->next;
        free(t);
    }
    *first=NULL;
    *first=(stac*)malloc(sizeof(stac));///coincides with init funciton from hash.h
    (*first)->val=NULL;                 /**-||-**/
    (*first)->next=NULL;
}
