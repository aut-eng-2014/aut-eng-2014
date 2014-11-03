#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "util.h"

char* printPadding(char* string, char padding)
{
    int size = 8;
    char* result = (char*) calloc(size+1, sizeof(char));
    int sizeString;
    if (string == NULL)
    {
        sizeString = 0;
    }
    else
    {
        sizeString = strlen(string);
    }
    if (size < sizeString)
    {
        for (int i=0; i<size; i++)
        {
            *(result+i) = *(string+i);
        }
    }
    else
    {
        for (int i=0; i<sizeString; i++)
        {
            *(result+i) = *(string+i);
        }
        for (int i=sizeString; i<size; i++)
        {
            *(result+i) = padding;
        }
    }
    return result;
}

bool randBool()
{
    static bool init = true;
    if (init)
    {
        srand(time(NULL));
        init = false;
    }
    return rand()%2;
}
