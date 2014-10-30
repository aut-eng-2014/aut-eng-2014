#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int x;
    struct node *stanga, *dreapta;
} structura;
structura *nod(int x)
{
    structura *node = (structura *)malloc(sizeof(structura));
    node->x = x;
    node->stanga = node->dreapta = NULL;
    return(node);
}
void inorder(structura *radacina)
{
    if (radacina != NULL)
    {
        inorder(radacina->stanga);
        //   printf("\t%d",radacina->x);
        inorder(radacina->dreapta);
    }
}

void fix_pointer(structura *radacina)
{
    static struct node *pre = NULL;

    if (radacina != NULL)
    {
        fix_pointer(radacina->stanga);
        radacina->stanga = pre;
        pre = radacina;
        fix_pointer(radacina->dreapta);
    }
}


structura *fixnextpointer(structura *radacina)
{
    structura *previous = NULL;


    while (radacina && radacina->dreapta != NULL)
        radacina = radacina->dreapta;


    while (radacina && radacina->stanga != NULL)
    {
        previous = radacina;
        radacina = radacina->stanga;
        radacina->dreapta = previous;
    }
    return (radacina);
}
structura *copac_lista(structura *radacina)
{
    fix_pointer(radacina);
    return fixnextpointer(radacina);
}
void afisare(structura *radacina)
{
    while (radacina != NULL)
    {
        printf(" %d ", radacina->x);
        radacina = radacina->dreapta;
    }
}
int main(void)
{
    structura *radacina = nod(17);
    radacina->stanga        = nod(21);
    radacina->dreapta       = nod(26);
    radacina->stanga->stanga  = nod(32);
    radacina->stanga->dreapta = nod(38);
    radacina->dreapta->stanga = nod(41);
    inorder(radacina);
    struct node *head = copac_lista(radacina);
    printf("\n Out:");
    afisare(head);
    printf("\n");
    return 0;
}
