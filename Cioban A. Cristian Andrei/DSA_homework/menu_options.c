#include "functions_binsearchtree.h"
#include "menu_options.h"


nodeT *root = NULL;
nodeT *temp = NULL;
int value;

void mInsert() {
	printf("\nType the value you want to insert:");
	scanf("%d", &value);
	root = Insert(root, value);
	printf("\n");
}

void mDelete(){
	printf("\nType the node you want to delete:");
	scanf("%d", &value);
	root = Delete(root, value);
	printf("\n");
}

void mFind() {

	printf("\nType the node you want to find:");
	scanf("%d", &value);
	temp = Find(root, value);
	if (temp == NULL) {
		printf("Node not found!");
	}
	else {
		printf("Node found!");
	}
	printf("\n");
}

void mPrint (){
	int choice_print;
	printf("\nChoose a printing method. \n");
	printf("1. Preorder\n");
	printf("2. Inorder\n");
	printf("3. Postorder\n");
	scanf("%d", &choice_print);
	switch (choice_print)
	{
	case 1: {
		printf("\n");
		Preorder(root, 0);
		printf("\n");
	}
		break;
	case 2: {
		printf("\n");
		Inorder(root, 0);
		printf("\n");
	}
		break;
	case 3: {
		printf("\n");
		Postorder(root, 0);
		printf("\n");
	}
		break;
	default:
		break;
	}

}

