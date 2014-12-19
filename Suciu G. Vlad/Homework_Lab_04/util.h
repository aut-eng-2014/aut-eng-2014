#ifndef UTIL_HEADER
#define UTIL_HEADER

/* defining the boolean type */
typedef char bool;
#define true 1
#define false 0

/* characters used for printing the tree */
#define SYMBOL_EW 196
#define SYMBOL_ESW 194
#define SYMBOL_NE 192
#define SYMBOL_SW 191
#define SYMBOL_NS 179

/* returns string with padding condensed in a tab */
char* printPadding(char* string, char padding);

/* randomizes true/false */
bool randBool();

#endif
