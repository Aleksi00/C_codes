#include "source.h"
#include <stdlib.h>
#include <string.h>

/**
 * \brief Returns the number of occurrences of string sub in the string str.
 * 
 * \param str A null-terminated string that might contain sub in it. 
 * \param sub A null terminated string to search for.
 * \return The number of occurrences of sub in str.
 * 
 * \note strstr function declared in string.h might be useful. 
 */
int num_substr(const char* str, const char* sub) 
{
    int occurrence = 0;
    while ((str=strstr(str,sub)) != NULL)
    {
        str++;
        occurrence++;
    }
    return occurrence;
}
