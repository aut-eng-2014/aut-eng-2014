

# include <stdio.h>
# include <conio.h>
# include <stdlib.h>

typedef struct BinarySsearchTree {
   int val;
   struct BinarySsearcT *leftc, *rightc;
} node;

node* Fmin(node *value)
{
        if(value==NULL)
        {
               /* Cand nu este nici un element in arbore */
                return NULL;
        }
        if(value->leftc) /*Merge in stanga subarborelui sa gaseasca elemantul minimi */
                return Fmin(value->leftc);
        else
                return value;
}
node* Fmax(node *value)
{
        if(value==NULL)
        {

                return NULL;
        }
        if(value->rightc) /* Merge in dreapta subarborelui sa
                           gaseasaca elementul cel mai mare elemen*/
                Fmax(value->rightc);
        else
                return value;
}


node * Delete(node *value, int val)
{
         node *temp;

        if(value==NULL)
        {
        printf("Element Not Found");
        }
        else if(val < value->val)
        {
                value->leftc = Delete(value->leftc, val);
        }
        else if(val > value->val)
        {
                value->rightc = Delete(value->rightc, val);
        }
        else
        {
                /*Acum putem sterge valoarea si sa o inlocuim cu minimul
                din dreapta subarborelui sau cu maximul din stanga subarborelui */
                if(value->rightc && value->leftc)
                {
                        /* Inlocuim cu elementul cel mai mic element din dreapta a subarborelui */
                        temp = Fmin(value->rightc);
                        value -> val = temp->val;
                        /* Dupa ce inlocuim cu o alta valoare trebuie sa stergem valoarea precedenta */
                        value -> rightc = Delete(value->rightc,temp->val);
                }
                else
                {
                        /* Daca este doar un fiu sau acel nod nu are fii atunci putem sa stergem
                        acel nod din arbore si sa conectam parintele la copil */
                        temp = value;
                        if(value->leftc == NULL)
                                value = value->rightc;
                        else if(value->rightc == NULL)
                                value = value->leftc;
                        free(temp); /* temp is longer required */
                }
        }
        return value;

}

/*Aceasta functie cauta un nod in arbore*/

node *Find(node *root, int key, node **parent) {
   node *temp;
   temp = root;

   while (temp != NULL) {
      if (temp->val == key) {
         printf("\nThe %d Element is Present", temp->val);
         return temp;
      }
      *parent = temp;

      if (temp->val > key)
         temp = temp->leftc;
      else
         temp = temp->rightc;
   }
   return NULL;
}


void main() {
   char choice;
   char ans = 'N';
   int key;
   node *new_node, *root, *temp, *parent;
   node *get_node();
   root = NULL;


   printf("\nProgram For Binary Search Tree\n ");
   do {
      printf("\n1.For Isert Press:  i");
      printf("\n2.For Find Press:   f");
      printf("\n3.For Delete Press: d");
      printf("\n4.For Show Press:   s");
      printf("\n5.For Quit Press:   q\n");
      printf("\nEnter your choice:");
      scanf("%c", &choice);

      switch (choice) {
      case 'i':
         do {
            new_node = get_node();
            printf("\nEnter The Element ");
            scanf("%d", &new_node->val);

            if (root == NULL)
               root = new_node;
            else
               insert(root, new_node);

            printf("\nWant To enter More Elements?(y/n)");
            ans = getch();
         } while (ans == 'y');
         break;

      case 'f':
         printf("\nEnter Element to be searched :");
         scanf("%d", &key);

         temp = Find(root, key, &parent);
         printf("\nParent of node %d is %d", temp->val, parent->val);
         break;

      case 'd':
          printf("\nEnter Element to be deleted : ");
          scanf("%d",&key);
          temp = Delete(root,key) ;
          printf("The Element %d has been deleted",&key);
          break;

      case 's':
         if (root == NULL)
            printf("Tree Is Not Created");
         else {
            printf("\nThe Inorder display : ");
            showinorder(root);

         }
         break;
      }
   } while (choice != 'q');
}

/*Nod nou*/

node *get_node() {
   node *temp;
   temp = (node *) malloc(sizeof(node));
   temp->leftc = NULL;
   temp->rightc = NULL;
   return temp;
}

/*Aici se creaza arborele*/

void insert(node *root, node *new_node) {
   if (new_node->val < root->val) {
      if (root->leftc == NULL)
         root->leftc = new_node;
      else
         insert(root->leftc, new_node);
   }

   if (new_node->val > root->val) {
      if (root->rightc == NULL)
         root->rightc = new_node;
      else
         insert(root->rightc, new_node);
   }
}

/*Aici se afisaza arborele in inorder*/

void showinorder(node *temp) {
   if (temp != NULL) {
      showinorder(temp->leftc);
      printf(" %d ", temp->val);
      showinorder(temp->rightc);
   }
}
