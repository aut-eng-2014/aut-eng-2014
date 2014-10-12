#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

/* I thought a small change might make the assignment more fun, so I introduced wallets */
typedef struct node
{
    int money;
    struct node *before;
    struct node *after;
} WalletT;

WalletT *first, *last;

/* initializes the list with two nodes based on two values */
void init(int moneyFirst, int moneyLast)
{
    first = (WalletT*) malloc(sizeof(WalletT));
    last = (WalletT*) malloc(sizeof(WalletT));

    first->money = moneyFirst;
    last->money = moneyLast;

    first->before = NULL;
    first->after = last;
    last->before = first;
    last->after = NULL;
    printf("[INFO] [INIT]\tList initialized with First:%d Last:%d\n", moneyFirst, moneyLast);
    printf("\n");
}

/* counts the specified list */
int count(bool showInfo, WalletT *firstListElement, WalletT *lastListElement)
{
    int count = 1;
    WalletT *node = firstListElement;
    while (node != lastListElement)
    {
        count++;
        node = node->after;
    }
    if (showInfo)
    {
        printf("[INFO] [COUNT]\tNumber of nodes: %d\n", count);
        printf("\n");
    }
    return count;
}

/* searches the wallets to find the node with the exact amount of money speciffied,
returns 0 if no element is found */
int search(int money, bool printInfo)
{
    int nrWallets = count(false, first, last);
    WalletT *node = first;
    for (int i=0; i<nrWallets; i++)
    {
        if (node->money == money)
        {
            if (printInfo)
                printf("[INFO] [SEARCH]\tElement @ [%d], with money=%d was found.\n", i+1, money);
            return i+1;
        }
        node = node->after;
    }
    if (printInfo)
    {
        printf("[INFO] [SEARCH]\tNo element with money=%d was found.\n", money);
        printf("\n");
    }
    return 0;
}

/* creates and adds at the end or the beginning of the list the node based on the value money */
void add(int money, bool inFront)
{
    if (search(money, false))
    {
        printf("[WARN] [ADD]\tMoney=%d already exists.\n", money);
        return;
    }
    WalletT *node = (WalletT*) malloc(sizeof(WalletT));
    node->money = money;
    if (inFront)
    {
        node->before = NULL;
        node->after = first;
        first->before = node;
        first = node;
        printf("[INFO] [ADD]\tMoney=%d added @ front.\n", money);
    }
    else
    {
        node->before = last;
        node->after = NULL;
        last->after = node;
        last = node;
        printf("[INFO] [ADD]\tMoney=%d added @ back.\n", money);
    }
    printf("\n");
}

/* prints the list, also the first and last */
void show(WalletT *firstNode, WalletT *lastNode)
{
    int nrNodes = count(true, firstNode, lastNode);
    WalletT *node = firstNode;
    for (int i=0; i<nrNodes; i++)
    {
        printf("[INFO] [SHOW]\tWallet[%d]= money:%d\n", i+1, node->money);
        node = node->after;
    }
    printf("[INFO] [SHOW]\tFirst:%d Last:%d\n", firstNode->money, lastNode->money);
    printf("\n");
}

/* removes the node by position, first position is 1, returns true if node is removed, else false */
bool erase(int pos)
{
    /* exits if pos is out of bounds */
    int maxPos = count(false, first, last);
    if ((pos > maxPos) || (pos <= 0))
    {
        printf("[WARN] [ERASE]\tErase @ [%d] failed.\n", pos);
        printf("\n");
        return false;
    }

    /* get the correct node */
    WalletT *node = first;
    for (int i=0; i<pos-1; i++)
    {
        node = node->after;
    }

    /* decide if it is first or last */
    if (node->before != NULL)
        node->before->after = node->after;
    else
        first = first->after;
    if (node->after != NULL)
        node->after->before = node->before;
    else
        last = last->before;
    free(node);
    printf("[INFO] [ERASE]\tErase @ [%d] succeded.\n", pos);
    printf("\n");
    return true;
}

/* swaps the specified nodes */
void swap(WalletT **node1, WalletT **node2)
{
    /* swap the links with the list */
    if ((*node1)->after != NULL)
        (*node1)->after->before = *node2;
    if ((*node1)->before != NULL)
        (*node1)->before->after = *node2;
    if ((*node2)->after != NULL)
        (*node2)->after->before = *node1;
    if ((*node2)->before != NULL)
        (*node2)->before->after = *node1;

    /* swap the nodes between them */
    WalletT *swap = (WalletT*) malloc(sizeof(WalletT));
    swap->after = (*node1)->after;
    swap->before = (*node1)->before;
    (*node1)->after = (*node2)->after;
    (*node1)->before = (*node2)->before;
    (*node2)->after = swap->after;
    (*node2)->before = swap->before;
    free(swap);
    swap = *node1;
    *node1 = *node2;
    *node2 = swap;
    printf("[INFO] [SWAP]\tWallets with money=%d, money=%d were swapped.\n", (*node1)->money, (*node2)->money);
    printf("\n");
}

/* part of the sorting algorithm, merges two sorted lists together */
void merge(bool sortDesc, WalletT **firstA, WalletT **lastA, WalletT **firstB, WalletT **lastB)
{
    WalletT *node = (WalletT*) malloc(sizeof(WalletT));

    /* memorise first node to new list */
    WalletT *memFirst = node;

    /* link the new list to the external list */
    node->before = (*firstA)->before;
    if ((*firstA)->before != NULL)
    {
        (*firstA)->before->after = node;
    }
    else
    {
        first = node;
    }

    /* this while is until one of the two lists, A or B ends */
    while ((*firstA!=(*lastA)->after) && (*firstB!=(*lastB)->after))
    {
        /* memorize the before */
        WalletT *before = node->before;
        /* copy data and handle current list */
        if((((*firstA)->money > (*firstB)->money) && !(sortDesc)) || (!((*firstA)->money > (*firstB)->money) && (sortDesc)))
        {
            memcpy(node, *firstB, sizeof(WalletT));
            *firstB = (*firstB)->after;
        }
        else
        {
            memcpy(node, *firstA, sizeof(WalletT));
            *firstA = (*firstA)->after;
        }
        /* attribute memory to next and restore before element */
        node->after = (WalletT*) malloc(sizeof(WalletT));
        node->before = before;
        /* make the next element know who is before him */
        node->after->before = node;
        /* change to next node */
        node = node->after;
    }

    /* this while is if the list B ends first, addadd the remaining list A elements */
    while (*firstA!=(*lastA)->after)
    {
        WalletT *before = node->before;
        memcpy(node, *firstA, sizeof(WalletT));
        *firstA = (*firstA)->after;
        node->after = (WalletT*) malloc(sizeof(WalletT));
        node->before = before;
        node->after->before = node;
        node = node->after;
    }

    /* this while is if the list A ends first, add the remaining list B elements */
    while (*firstB!=(*lastB)->after)
    {
        WalletT *before = node->before;
        memcpy(node, *firstB, sizeof(WalletT));
        *firstB = (*firstB)->after;
        node->after = (WalletT*) malloc(sizeof(WalletT));
        node->before = before;
        node->after->before = node;
        node = node->after;
    }

    /* link the end of the new list to the full list, but first free unnecessary data*/
    node = node->before;
    free(node->after);
    node->after = (*lastB)->after;
    if ((*lastB)->after != NULL)
    {
        (*lastB)->after->before = node;
    }
    else
    {
        last = node;
    }

    /* point the function pointers to new list */
    *firstA = memFirst;
    *lastB = node;
}

/* sorts the list descending if true, ascending if false
sorting algorithm is of type MERGE SORT */
void sort(bool sortDesc, WalletT **firstListElement, WalletT **lastListElement)
{
    static bool printInfo = true;
    if (printInfo)
    {
        if (sortDesc)
            printf("[INFO] [SORT]\tSorting descending started. Show list for result.\n");
        else
            printf("[INFO] [SORT]\tSorting ascending started. Show list for result.\n");
        printf("\n");
        printInfo = false;
    }

    int listSize = count(false, *firstListElement, *lastListElement);

    /* exits the recursive function when list size is 1 */
    if (listSize == 1)
        return;

    /* split the list in 2 */
    WalletT *node = NULL;
    int middle = listSize/2;
    WalletT *firstA = *firstListElement;
    node = *firstListElement;
    for (int i=1; i<middle; i++)
        node = node->after;
    WalletT *lastA = node;
    WalletT *firstB = node->after;
    for (int i=middle; i<listSize; i++)
        node = node->after;
    WalletT *lastB = node;

    /* sort the splitted lists recursively */
    sort(sortDesc, &firstA, &lastA);
    sort(sortDesc, &firstB, &lastB);

    /* merge the splitted lists */
    merge(sortDesc, &firstA, &lastA, &firstB, &lastB);

    /* assign new list to external list */
    *firstListElement = firstA;
    *lastListElement = lastB;
}

int main()
{
    init(10, 12);
    show(first, last);
    add(80, false);
    show(first, last);
    if (erase(1))
    {
        show(first, last);
    }
    add(64, true);
    add(54, false);
    add(21, true);
    add(0, false);
    add(53, true);
    add(22, false);
    add(202, false);
    add(34, false);
    add(44, true);
    add(1009, true);
    show(first, last);
    sort(false, &first, &last);
    show(first, last);
    return 0;
}
