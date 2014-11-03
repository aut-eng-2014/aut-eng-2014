#include "functions.h"

unsigned long long codeGen(int value)
{
    unsigned long long cd=0b001000000000000000000000000000;///Sets the bit according to microsoft convention, for non-microsoft error
    if (value<67108864)
        cd+=value;
    return cd;
}

node* createBinaryTree()
{
    char c,sign=1;
    short e1=0,e2=0;///I use 'e' as a temporary bool variable. E as in error, exeption or エッ*
                  ///probable if there are two i could relate to "eset" aswell, wich means "case" in Hungarian. I couldn't use as an abbreviation for "case" anyhow, cause I use c for chars
    do
        fscanf(f,"%c",&c);
    while (c==' ');

    node* p=NULL;///I've heard it's a good habit to set pionters to NULL on declaration
    if ((c=='+') || (c=='-'))///if you finish doing the excercise long enough it will go on the positive side of the if:P
    {
        sign=c;
        fscanf(f,"%c",&c);
        if (c==' ')///this checks if it is a sign of a number or an operator
        {
            e1=1;
            c=sign;
        }
        else
        {
            e2=1;
        }
    }
    if ((e2) || ((c>47) && (c<58)))///e2 means that it was a sign, and the number after it needs to be read; or there was no sign
    {
        int *n=(int*)malloc(sizeof(int));
        *n=0;
        while ((c!=' ') && (c!='.'))
        {
            *n=*n*10+c-48;
            if (fscanf(f,"%c",&c)<0)///if the file looks as it is supposed to, it should end in a digit
                break;
        }

        if (c=='.')///the only other possibility to encounter ' ' in the previous while=> integer
        {
            float *fl=(float*)malloc(sizeof(float));
            *fl=*n;
            float exponent=0.1;
            fscanf(f,"%c",&c);
            while (c!=' ')
            {
                *fl+=(c-48)*exponent;
                exponent*=0.1;
                if (fscanf(f,"%c",&c)<0)
                    break;
            }
            p=(node*)malloc(sizeof(node));
            p->val=fl;
            p->type='f';
            p->left=NULL;
            p->right=NULL;
            if (sign=='-')///p->val is a pointer to fl, therefore this WILL have an effect
                *fl*=-1;
        }
        else///this else is active if the number was an integer
        {
            p=(node*)malloc(sizeof(node));
            p->val=n;
            p->type='n';
            p->left=NULL;
            p->right=NULL;
        }

        if (sign=='-')///p->val is a pointer, therefor this WILL have an effect
        {
            *n*=-1;///it has to be n and not p->val, otherwise in the case of a float, it would re-change the sign from line 75
        }
    }

    if ((c=='/') || (c=='*') || (e1)) ///reminder: e1 is active if c was a + or - OPERATOR, not sign
    {
        char * cp=(char*)malloc(sizeof(char));
        *cp=c;
        p=(node*)malloc(sizeof(node));
        p->val=cp;
        p->type='c';

        p->left=createBinaryTree();
        p->right=createBinaryTree();
    }

    return p;
}

void preorder(node* root)///i won't comment these 3, i guess they're pretty straight-forward
{
    if (root!=NULL)
    {
        switch (root->type)
        {
        case 'n':
            printf("%d | ",*(int*)root->val);
            break;
        case 'c':
            printf("%c | ",*(char*)root->val);
            break;
        case 'f':
            printf("%.2f | ",*(float*)root->val);
            break;
        }
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node * root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        switch (root->type)
        {
        case 'n':
            printf("%d | ",*(int*)root->val);
            break;
        case 'c':
            printf("%c | ",*(char*)root->val);
            break;
        case 'f':
            printf("%.2f | ",*(float*)root->val);
            break;
        }
        inorder(root->right);
    }
}

void postorder(node *root)/// I don't think it was required, but i will do it just for the gigs:))
{
    if (root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        switch (root->type)
        {
        case 'n':
            printf("%d | ",*(int*)root->val);
            break;
        case 'c':
            printf("%c | ",*(char*)root->val);
            break;
        case 'f':
            printf("%.2f | ",*(float*)root->val);
            break;
        }
    }
}


void match(const node* from, lst* to)
{
    to->val=from->val;
    to->type=from->type;
}

void lstInit()
{
    first=(lst*)malloc(sizeof(lst));
    last=(lst*)malloc(sizeof(lst));

    first->prev=NULL;
    first->next=last;

    last->next=NULL;
    last->prev=first;

    firstAcces=2;
}

void createListFromTree (node * p)
{
    switch (firstAcces)
    {
    case 2:
        match(p,first);
        firstAcces=1;
        createListFromTree(p->left);
        createListFromTree(p->right);
        break;
    case 1:
        match(p,last);
        firstAcces=0;
        createListFromTree(p->left);
        createListFromTree(p->right);
        break;
    default:
        if (p!=NULL)
        {
            lst * temp=(lst*)malloc(sizeof(lst));///If I wanted to create the stack from the tree, delete from here
            match(p,temp);
            last->next=temp;
            temp->prev=last;
            temp->next=NULL;
            last=temp;                              ///to here and replace it with the code from the calculate function below
                                                    ///or use a function pointer, pass it as argument, and put it here
            createListFromTree(p->left);
            createListFromTree(p->right);
        }
        break;
    }
}

void initCreateTreeFromList()
{
    l=first;
}

node* createTreeFromList()///in light of what you have just showed me, I will try to make a simpler conversion
{
    node * p=(node*)malloc(sizeof(node));

    p->val=l->val;
    p->type=l->type;

    if (l->type=='c')
    {
        l=l->next;
        p->left=createTreeFromList(l);
        l=l->next;
        p->right=createTreeFromList(l);
    }
    else
    {
        p->left=NULL;
        p->right=NULL;
    }
    return p;
}

lst* pop(lst* s)///returns the new (last element)
{
    if (s!=NULL)
    {
        s=s->prev;
        free(s->next);
        s->next=NULL;
    }
    return s;
}

lst * push(lst * s,lst * source)///to change the itrator, as a parameter, i would need a **, which I have found to be a pain in the neck
{                               ///=>return value
    char e=0;
    lst* temp;
    if (s!=NULL)
    {
        temp=s;
        s=s->next;
    }
    else
    {
        e=1;
    }

    s=(lst*)malloc(sizeof(lst));

    if (source->type=='n')
    {
        s->type='f';
        s->val=(float*)malloc(sizeof(float));
        *(float*)(s->val)=*(int*)(source->val);
    }
    else
    {
        s->val=source->val;///the proper way would be to allocate memory based on type, beacause as it is now, if the source is freed, this is aswell=>fragmentatino failure
        s->type=source->type;
    }

    s->next=NULL;

    if (e)
        s->prev=NULL;
    else
        s->prev=temp;


    return s;
}

float calculate() ///prof Joldos said that it should be something like this, if I recall correctly. It's easier to create from the list than, the tree if I have the list anyway
{
    lst * itrator=NULL,*l=first;
    while (l!=NULL)
    {
        itrator=push(itrator,l);///to change the itrator, as a parameter, i would need a **, which I have found to be a pain in the neck


        while ((itrator->prev!=NULL)&&((itrator->type=='f') && (itrator->prev->type=='f'))) ///ensures to to the math, if the popping results in a new operation
        {
            float n1=*(float*)itrator->val,n2=*(float*)itrator->prev->val;
            char oprator=*(char*)itrator->prev->prev->val;
            itrator=pop(itrator);itrator=pop(itrator);///pops the last two numbers, the itrator should be pointing to the sign, which will be replaced w/ the result

            itrator->type='f';
            free(itrator->val);///otherwise I will be writing 4 bytes into 1 byte
            itrator->val=(float*)malloc(sizeof(float));

            switch (oprator)
            {
            case '+':
                *(float*)itrator->val=n1+n2;
                break;
            case '-':
                *(float*)itrator->val=n1-n2;
                break;
            case '*':
                *(float*)itrator->val=n1*n2;
                break;
            case '/':
                *(float*)itrator->val=n1/n2;
                break;
            }
        }
        l=l->next;
    }
    return *(float*)itrator->val;/// the last element should now be the result
}

void printlst()///just an auxiliary function to see if the stack is good. Or evil
{
    lst * l=first;
    while (l!=NULL)
    {
        switch (l->type)
        {
        case 'n':
            printf("%d | ",*(int*)l->val);
            break;
        case 'c':
            printf("%c | ",*(char*)l->val);
            break;
        case 'f':
            printf("%.2f | ",*(float*)l->val);
            break;
        }
        l=l->next;
    }

}
