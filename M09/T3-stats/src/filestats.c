#include <ctype.h>
#include "filestats.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * \brief Returns the number of lines in a file. 
 * 
 * \param filename The name of the file.
 * \return The number of lines in the file, or -1 if an error occurs. 
 */
int line_count(const char* filename) 
{
    char a[256];
    int line_count = 0;
	FILE *fp = fopen(filename,"r");
    if (fp == NULL)
    {
        return -1;
    }
    char* chr = fgets(a,0x1000,fp);
    while (chr != NULL)
    {  
        line_count++;
        chr = fgets(a,0x1000,fp);
        if (feof(fp) == '\n')
        {
            break;
        }     

    }
    fclose(fp);
    return line_count;

}

/**
 * \brief Returns the number of words in a file.
 * 
 * \details The function assumes that a word is formed by alphabetical characters
 *          as defined in ctype.h so that isalpha() returns nonzero value.
 * 
 *          The words are separated by a white space character as defined in 
 *          ctype.h so that isspace() returns nonzero value.
 * 
 * \param filename The name of the file.
 * \return The number of words in the file, or -1 if an error occurs.
 */
int word_count(const char* filename) 
{
    int i;
    int word_count = 0;
    int in_the_word = 0;
    char s[1000] = {0};
    FILE *fp = fopen(filename,"r");
    if (fp == NULL)
    {
        return -1;
    }

    for (;;)
    {
        int a = fread(s,1,1000,fp);
        if (ferror(fp))
            return -1;
        for( i=0 ; i<a ; i++)
        {
            if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\0')
            {
                if (in_the_word)
                {
                    word_count++;
                    in_the_word=0;
                }
            }
            
            else if (isalpha(s[i]))
            {
                in_the_word=1;
            }
        }
        if (feof(fp))
        {
            if (s[i-1] != '\n' && s[i-1]!= '\0')
                word_count++;
            break;
        }
    }
    fclose(fp);
    return word_count;
}
