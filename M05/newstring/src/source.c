#include "source.h"
#include <stdio.h>

/* Print string */
/* Parameters:
 * s: string to be printed */

/**
 * \brief Prints ? terminated string
 *
 * \param s A ? terminated string
 */
void qstr_print(const char *s)
{
    int i;
    for (i = 0; s[i] != '?' ; i++)
    {
        printf("%c",s[i]);
    }
}   

/**
 * \brief Returns the length of a ? terminated string
 *
 * \param s A ? terminated string
 * \return The number of characters before first occurrence of ?
 */
unsigned int qstr_length(const char *s)
{
    int i;
    int counter = 0;
    for (i = 0; s[i] != '?'; i++)
    {
        counter = counter + 1;
    }
    return counter;
}

/**
 * \brief Concatenates two ? terminated strings
 *
 * \param dst The ? terminated string that will contain the concatenated ? terminated string
 * \param src A ? terminated string that will be appended to dst.
 * \return The length of the dst after concatenation
 */
int qstr_cat(char *dst, const char *src)
{
    int i = 0;
    int j = 0;

    while ( dst[i] != '?')
    {
        i++;
    }
    while ( src[j] != '?')
    {
        dst[i] = src[j];
        j++;
        i++;
    }
    int k;
    dst[i] = '?';
    int counter = 0;
    for (k = 0; dst[k] != '?'; k++)
    {
        counter = counter + 1;
    }
    return counter;

}
