#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
        int value;
        struct node *left;
        struct node *right;
};
typedef struct node Node;

void treetoListRec(Node * node, Node ** last, Node **ptrToHead){
        if(node == NULL)
                return;
        if(node->left)
                treetoListRec(node->left, last, ptrToHead);

        if(*last != NULL){
                (*last)->right = node;
        }
         else{
                 *ptrToHead = node;
         }

        node->left = *last;
        *last = node;

        if(node->right)
                treetoListRec(node->right, last, ptrToHead);

}
Node * create_node(int value){
        Node * temp =  (Node *)malloc(sizeof(Node));
        temp->value = value;
        temp->right= NULL;
        temp->left = NULL;
        return temp;
}
Node * addNode(Node *node, int value){
        if(node == NULL){
                return create_node(value);
        }
        else{
          if (node->value > value){
                node->left = addNode(node->left, value);
          }
          else{
                node->right = addNode(node->right, value);
          }
        }
        return node;
}

void traverse(Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->value);
        p = p->right;
    }
}


int main(){
        Node *root = NULL;
        Node * last = NULL;
        Node *ptrToHead = NULL;
        //Creating a binary tree
        root = addNode(root,30);
        root = addNode(root,20);
        root = addNode(root,15);
        root = addNode(root,25);
        root = addNode(root,40);
        root = addNode(root,37);
        root = addNode(root,45);

        treetoListRec(root,&last, &ptrToHead);

        traverse(ptrToHead);


        return 0;
}
