#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    struct node *prev;
    int val;
} nodex;
nodex *first;
nodex *last;
//initialization of the list
void init()
{
    first = (nodex*)malloc(sizeof(nodex));
    last = (nodex*)malloc(sizeof(nodex));
    first->val = 1;
    last->val = 5;
    first->next = last;
    first->prev = NULL;
    last->next = NULL;
    last->prev = first;
}
//a function for printing the list
void display()
{
    nodex * term = (nodex*)malloc(sizeof(nodex));
    term = first;
    if (first == NULL)
    {
        printf("\nThe list is void");
    }
    else
    {
        printf("\nThe formed list is: ");
        while (term != NULL)
        {
            printf("%d ", term->val);
            term = term->next;
        }
    }
    printf("\n");
}
//add last funtion
void addlast(int x)
{
    nodex *term = (nodex *)malloc(sizeof(nodex));
    term->val = x;
    term->next = NULL;
    term->prev = last;
    last->next = term;
    last = term;
}
//add first function
void addfirst(int x)
{
    nodex *term = (nodex *)malloc(sizeof(nodex));
    term->val = x;
    term->prev = NULL;
    term->next = first;
    first->prev = term;
    first = term;

}
// delete by key
void del(int x)
{
    nodex *term = (nodex *)malloc(sizeof(nodex));
    term = first;
    while (term != NULL)
    {
        if (term->val == x)
        {
            break;
        }
        term = term->next;
    }
    if (term == first)
    {
        first = first->next;
        first->prev = NULL;
        free(term);
    }

    else
    {
        term->next->prev = term->prev;
        term->prev->next = term->next;
        free(term);
    }
}
//The count funtion; returns the number of elements in the list
int count()
{
    int i = 0;
    nodex * term = (nodex*)malloc(sizeof(nodex));
    term = first;

    while (term != NULL)
    {
        i++;
        term = term->next;
    }
    return i;

}
// the swap function for sorting
void node_swap(nodex *left, nodex *right)
{
    nodex *tmp;

    tmp = left->prev;
    if (tmp)
        tmp->next = right;
    right->prev = tmp;
    left->prev = right;
    left->next = right->next;
    right->next = left;
    if (left->next != NULL)
        left->next->prev = left;
    if (right->prev == NULL) first = right;
}
//descending sorting
void sort_desc()
{
    nodex* term1;
    nodex* term2;
    term1 = first;
    term2 = last;
    while (term2 != first)
    {
        term1 = first;
        while (term1->next != NULL)
        {

            if (term1->val < term1->next->val)
            {
                node_swap(term1, term1->next);
            }
            else term1 = term1->next;

        }
        if (term2->prev == NULL) term2 = last;
        else term2 = term2->prev;
    }
    last=last;
}
int main()
{
    init();
    display();
    addlast(20);
    display();
    addlast(10);
    display();
    sort_desc();
    display();
    printf("\nThe number of elements is:%d\n", count());
    return 0;
}
