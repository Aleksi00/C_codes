#include "source.h"

#include <stdlib.h>
#include <string.h>

char *mystrcat(char *dest, const char *src)
{
     char *temp = NULL;
        char *origdest = dest;
    while (*dest)
    {
        dest++;
    }

    while (*src)
    {
        temp = realloc(origdest, strlen(origdest) + sizeof(char));
        *dest++ = *src++; // Copy the source
    }
    dest = temp;

    return origdest;
}
