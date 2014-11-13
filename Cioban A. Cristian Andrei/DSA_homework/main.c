#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "functions_binsearchtree.h"
#include "menu_options.h"

int main() {

	int choice;
	do
	{
		printf("\nMenu\n\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Find\n");
		printf("4. Show\n");
		printf("5. Exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1: /*Insert*/
			mInsert();
				break;
			case 2: /*Delete*/
			mDelete();
				break;


			case 3:/*Find*/
			mFind();
				break;


			case 4: /*Show*/
			mPrint();
			break;

			case 5: printf("Goodbye\n");
			break;
			default: printf("Wrong Choice. Enter again\n");
			break;
		}
		printf("\n");
	} while (choice != 5);

	return 0;

}
