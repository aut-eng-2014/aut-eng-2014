#include <stdlib.h>
#include "list.h"
#include "node.h"

ListT* list_header()
{
    ListT* header = (ListT*) malloc(sizeof(ListT));
    header->size = 0;
    return header;
}

NodeT* list_node(ListT* header, int pos)
{
    NodeT* node = header->first;
    for(int i=1; i<pos; i++)
    {
        node = node->next;
    }
    return node;
}

void* list_get(ListT* header, int pos)
{
    if ((header->size == 0) || (pos > header->size) || (pos <= 0))
    {
        return NULL;
    }
    else
    {
        NodeT* node = list_node(header, pos);
        return node->value;
    }
}

char list_contains(ListT* header, void* value)
{
    for (int i=0; i< header->size; i++)
    {
        if (list_get(header, i+1) == value)
        {
            return 1;
        }
    }
    return 0;
}

void list_add(ListT* header, void* value)
{
    if (header->size == 0)
    {
        header->first = createNode(value);
    }
    else
    {
        NodeT* node = list_node(header, header->size);
        node->next = createNode(value);
        node->next->before = node;
    }
    (header->size)++;
}

void list_unique(ListT* header)
{
    void* value;
    for (int i=0; i< header->size; i++)
    {
        value = list_get(header, i+1);
        for (int j=i+1; j< header->size; j++)
        {
            if (value == list_get(header, j+1))
            {
                list_remove(header, j+1);
            }
        }
    }
}

void* list_remove(ListT* header, int pos)
{
    if ((header->size == 0) || (pos > header->size) || (pos <= 0))
    {
        return NULL;
    }
    else
    {
        NodeT* node = list_node(header, pos);
        if (node->before != NULL)
        {
            node->before->next = node->next;
        }
        if (node->next != NULL)
        {
            node->next->before = node->before;
        }
        (header->size)--;
        void* val = node->value;
        free(node);
        return val;
    }
}
