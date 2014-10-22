#include "DLList.h"

node * getNode(unsigned int p) ///*private*
{
    if (p>=lngth)
        p=lngth;   ///could use NULL pointer as well, depending on safety of accuracy first
    node * t;
    int i;
    if (p<=lngth/2)
        for (i=0, t=f;i<p;i++)///p is unsigned=> can't use p-1
            t=t->next;
    else
        for (i=lngth,t=l;i>p+1;i--)
            t=t->prev;
    return t;
}

node * getCurrentNode()
{
    return getNode(iteratr);
}
node * getNextNode()
{
    if (iteratr<lngth)
        iteratr++;
    return getNode(iteratr);
}

void resetIteratr()
{
    iteratr=0;
}
void moveIteratr(unsigned int p)
{
    if (p>=lngth)
        iteratr=lngth;
    else
        iteratr=p;
}

void init(int x, int y)
{
    f=(node*) malloc(sizeof(node));
    l=(node*) malloc(sizeof(node));
    f->next=l;
    f->prev=NULL;
    l->next=NULL;
    l->prev=f;
    f->val=x;
    l->val=y;

    iteratr=0;
    lngth=2;
}

void addFirst(int x)
{
    node * n=(node*)malloc(sizeof(node));
    n->val=x;
    n->prev=NULL;
    n->next=f;
    f->prev=n;
    f=n;

    lngth++;
}

void addLast(int x)
{
    node * n=(node*)malloc(sizeof(node));
    n->val=x;
    n->next=NULL;
    n->prev=l;
    l->next=n;
    l=n;

    lngth++;
}

void insrt(unsigned int p,int x)
{
    if (p==0)
        addFirst(x);
    else
    if (p>=lngth)
        addLast(x);
    else
    {
        int i;
        node *n=(node*)malloc(sizeof(node));
        node *t;
        if (p<=lngth/2)
            for (i=0, t=f;i+1<p;i++)///p is unsigned=> can't use p-1
                t=t->next;
        else
            for (i=lngth,t=l;i>p;i--)
                t=t->prev;
        n->val=x;
        n->prev=t;
        n->next=t->next;
        (t->next)->prev=n;
        t->next=n;
    }

    lngth++;
}

void insrtS(unsigned int p,unsigned int w, ... )
{
    if (w==0)
        return;
    node * t=NULL,*t2;
    int i;

    if (p>lngth)
        p=lngth;

    if (p<=lngth/2)
        for (i=0, t=f;i+1<p;i++)///p is unsigned=> can't use p-1
            t=t->next;         ///maybe i should have made this a function, considering I implemented it 3 times...
    else                        ///I did create it as of 0.2.1, but i'm too lazy to replace all these fuctions, and possibly debug it
        for (i=lngth,t=l;i>p;i--)
            t=t->prev;
    if (p!=0)
        t2=t->next; ///if p==lngth it should become NULL pointer, which will be used a few lines below

    va_list args;
    va_start(args,w);
    if (p==0)
    {
        w--;
        lngth++;
        t2=f;
        t=(node*)malloc(sizeof(node));
        t->prev=NULL;
        f->prev=t;
        t->next=f;///in case the w==1,  this would not be overwritten in the for cicle below, hence broken chain
        f=t;
        t->val=va_arg(args,int);
    }
    for (i=0;i<w;i++)
    {
        node * n = (node*)malloc(sizeof(node));
        n->prev=t;
        n->val=va_arg(args,int);
        n->prev->next=n;
        t=n;
        n=NULL;
    }

    if (p!=lngth)
        t2->prev=t;
    t->next=t2;///this is a few lines below that
    if (p==lngth)
        l=t;
    va_end(args);
    lngth+=w;
}

void rmv(unsigned int p)
{
    node * t;
    int i;
    if (p==0)
    {
        f->next->prev=NULL;
        t=f->next;
        free(f);
        f=t;
        lngth--;
        return;
    }
    if (p==lngth-1)
    {
        l->prev->next=NULL;
        t=l->prev;
        free(l);
        l=t;
        lngth--;
        return;
    }
    if (p>=lngth)
        return;
    if (p<=lngth/2)
        for (i=0, t=f;i<p;i++)
            t=t->next;
    else
        for (i=lngth,t=l;i>p+1;i--)
            t=t->prev;
    t->prev->next=t->next;
    t->next->prev=t->prev;
    free(t);
    lngth--;
}

void rmvS(unsigned int p, int w)
{
    if (p>=lngth)
        return;
    if (p+w>=lngth)
        w=lngth-p;
    node * t,*t2;
    int i;
    if (p+w/2<=lngth/2)
    {
        for (i=0, t=f;i+1<p;i++) ///p-1 can't be used because its unsigned
            t=t->next;
        for (i=0,(p==0?(t2=t):(t2=t->next));i<w;i++)
        {
            t2=t2->next;
            free(t2->prev);
        }
        if (p==0)
        {
            t2->prev=NULL;
            f=t2;
        }
        else
        {
            t2->prev=t;
            t->next=t2;
        }

    }
    else
    {
        for (i=lngth,t=l;i>p+w+1;i--)
            t=t->prev;
        for (i=0,(p+w==lngth?(t2=t):(t2=t->prev));i<w;i++)
        {
            t2=t2->prev;
            free(t2->next);
        }
        if (p+w==lngth)
        {
            t2->next=NULL;
            l=t2;
        }
        else
        {
            t2->next=t;
            t->prev=t2;
        }
    }
    lngth-=w;
}

void rmvVal(int n)
{
    node *t =srch(n);
    if (t==NULL)
        return;
    t->prev->next=t->next;
    t->next->prev=t->prev;
    free(t);
    lngth--;
}

void rmvValS(int n)
{
    node *t=srch(n);
    while (t!=NULL)
    {
        t->prev->next=t->next;
        t->next->prev=t->prev;
        free(t);
        lngth--;
        t=srch(n);
    }
}

int getNodeValue(int p)
{
    if (p>=lngth)
        p=lngth;
    return getNode(p)->val;
}

node* srch(int n)
{
    node * t;
    t=f;
    while ((t!=NULL) && (n!=t->val)) ///the t!=NULL is evaluated first, therefore there is no risk of t->val causing segmentation fault
    {
        t=t->next;
    }
    return t;
}

int srchIndex(int n)
{
    node * t;
    int i=0;
    t=f;
    while ((n!=t->val) && (t->next!=NULL))
    {
        i++;
        t=t->next;
    }
    if ((t->next==NULL) && (t->val!=n))
        return -1;

    return i;
}
int cnt()
{
    node *t=f;
    int i=1;
    while (t->next!=NULL)
    {
        t=t->next;
        i++;
    }

    return i;///or return lngth
}
int getNextNodeValue()
{
    if (iteratr<lngth)
        iteratr++;
    return getNodeValue(iteratr);
}

void srt()
{
    int i,j,x;
    node *t,*t2;
    t=f;
    t2=t;
    for (i=1;i<lngth;i++)
    {
        for (j=i+1;j<=lngth;j++)   ///if I didn't have lngth, I'd have used a while(t2!=NULL) or something similar
        {
            t2=t2->next;
            if (t->val>t2->val)///I know it can be done w/out using the auxiliary variable, but this is simpler in my opinion
            {
                x=t->val;
                t->val=t2->val;
                t2->val=x;
            }
        }
        t=t->next;
        t2=t;
    }
}

void printNode(unsigned int p)
{
    printf("%d",getNode(p)->val);
}

void printNodeS(unsigned int p, int w)
{
    if (p+w>=lngth)
        w=lngth-p;
    if (w<=0)
        return;
    node * t=getNode(p);
    int i;
    printf("%d",t->val);  ///this is needed to not print a | after the last value
    for (i=1;i<w;i++)
    {
        t=t->next;
        printf(" | %d",t->val);
    }
    printf("\n");
}

void printNextNode()
{
    if (iteratr<lngth)
        iteratr++;
    printf("%d",getNodeValue(iteratr));
}

void printAll ()
{
    node * t=f;
    while(t->next!=NULL)
    {
        printf("%d | ",t->val);
        t=t->next;
    }
    printf("%d\n",t->val);
}

void destruct()
{
    int i;
    node * t=f;
    for (i=0;i+1<lngth;i++)
    {
        t=t->next;
        free(t->prev);
    }
    free(t);
    lngth=0;f=NULL;l=NULL;
}
