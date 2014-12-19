#ifndef MENU_HEADER
#define MENU_HEADER

//@override
void insertNode();

//@override
void deleteNode();

//@override
void findNode();

//@override
void showTree();

/* prints [INSERT] then accesses insertNode() */
void menuInsertNode();

/* prints [DELETE] then accesses deleteNode() */
void menuDeleteNode();

/* prints [FIND] then accesses findNode() */
void menuFindNode();

/* prints [SHOW] then accesses showTree() */
void menuShowTree();

/* prints the menu to stdin */
void printMenu();

/* returns the possible entrances in the menu as a character string */
char* initMenu();

/* starts the menu */
void runMenu();

#endif
