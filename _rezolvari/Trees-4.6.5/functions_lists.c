#include "functions.h"

/**
* A special "addLast" function for our list
*/
void addLast(char *key)
{
    if(first==NULL){
        first = (NodeL*)malloc(sizeof(NodeL));
        first-> content = key;
        first->prev=NULL;
    }
    else if(last==NULL)
    {
        last = (NodeL*)malloc(sizeof(NodeL));
        last->content= key;
        first->next = last;
        last->prev = first;
        last->next=NULL;
    }
    else
    {
        NodeL *node = (NodeL*) malloc(sizeof(NodeL));
        node->content= key;

        node->prev = last;
        node->next = NULL;
        last->next = node;
        last = node;
    }
}

/**
* "Exhaustive" deleteNode function
*/
void deleteNode(NodeL *node)
{
    if(node==first)
    {
        if(node->next == NULL)
        {
            first=NULL;
            // redundant..
            last=NULL;
        }
        else
        {
            if(node->next == last)
            {
                first=last;
            }
            else
            {
                first = node->next;
                first->prev = NULL;
            }
        }
    }
    else if(node == last){
        // weird case, but MAYBE SOMEHOW it happens
        if(node->prev == NULL){
            free(node);
            last=NULL;
            // redundant
            first=NULL;
        }
        else{
            if(node->prev == first){
                first-> next = NULL;
                last = NULL;
            }
            else{
                last = node->prev;
                last->next = NULL;
            }
        }
    }
    // "in between" node
    else{
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    free(node);
}

void traverseList()
{
    NodeL *temp = first;

    while(temp!=NULL)
    {
        printf("%s ",temp->content);
        temp = temp->next;
    }
    printf("\n\n");
}
