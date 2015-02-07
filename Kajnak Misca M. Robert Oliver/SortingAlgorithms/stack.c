#include "stack.h"

void stInit (stac** st,int n)
{
    *st=(stac*)malloc(sizeof(stac));
    (*st)->val=n;
    (*st)->next=NULL;
}

void stInsert(stac** st,int n)
{
    if (*st==NULL)
    {
        *st=(stac*)malloc(sizeof(stac));
        (*st)->val=n;
        (*st)->next=NULL;
        return;
    }

    stac *t=(stac*)malloc(sizeof(stac));
    t->val=n;
    t->next=NULL;

    stac *iter=*st;
    while (iter->next!=NULL)
        iter=iter->next;
    iter->next=t;

}

int stPop(stac** st)
{
    if (*st==NULL)
        return -1;
    if ((*st)->next==NULL)
    {
        int n=(*st)->val;
        free(*st);
        *st=NULL;
        return n;
    }
    stac *iter=(*st)->next,*last=*st;
    while (iter->next!=NULL)
    {
        last=iter;
        iter=iter->next;
    }
    int n=iter->val;

    free(iter);
    last->next=NULL;
    return n;
}

int stDequeue(stac ** st)
{
    if (*st==NULL)
        return -1;

    int n=(*st)->val;
    stac *t=(*st)->next;
    free(*st);
    *st=t;
    return n;
}
