#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "menu.h"

char* initMenu()
{
    return "IDFSQ";
}

void printMenu()
{
    printf("[MENU]\tI. Insert D. Delete F. Find S. Show Q. Quit\n\n");
}

void menuInsertNode()
{
    printf("[INSE]\t");
    insertNode();
    printf("\n\n");
}

void menuDeleteNode()
{
    printf("[DELE]\t");
    deleteNode();
    printf("\n\n");
}

void menuFindNode()
{
    printf("[FIND]\t");
    findNode();
    printf("\n\n");
}

void menuShowTree()
{
    printf("[SHOW]\t");
    showTree();
    printf("\n\n");
}

void runMenu()
{
    bool run = true;
    char *menu = initMenu();
    while (run)
    {
        system("cls");
        printMenu();
        char c = toupper(getch());
        switch(c)
        {
            case 'I':
                menuInsertNode();
                break;
            case 'D':
                menuDeleteNode();
                break;
            case 'F':
                menuFindNode();
                break;
            case 'S':
                menuShowTree();
                break;
            case 'Q':
                printf("[EXIT]\tSystem exiting...\n\n");
                run = false;
                break;
        }
        if (strchr(menu, c) != NULL)
        {
            printf("\nPress any key to continue...\n");
            getch();
        }
    }
}
