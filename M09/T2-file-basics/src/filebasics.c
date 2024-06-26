#include "filebasics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Print the given text file to the standard output stream.
 * 
 * \param filename The name of the file
 * \return The number of characters printed or -1 if file opening or reading 
 *         fails.
 */
int print_file_and_count(const char* filename) 
{
    int count = 0;
	FILE *fp = fopen(filename,"r");
    if (fp == NULL)
    {
        return -1;
    }
    char chr = fgetc(fp);
    while (chr != EOF)
    {
         printf("%c",chr);
         chr = fgetc(fp);
         count++;
    }
    fclose(fp);
    return count;
}

/**
 * \brief Compares two files and returns the first line that differ
 *        in the two files, concatenated together, separated by four dashes, on
 *        different lines.      
 * 
 * \param file1 The name of the first file
 * \param file2 The name of the second file
 * 
 * \note You can assume that lines are not longer than 1000 characters.
 * 
 * \return A dynamically allocated string that contains the first different 
 *         lines in the files. An example string is 
 * 
 *            printf("Hello world!\n");
 *       ----
 *            printf("Hello world\n");
 * \returns NULL if the files are equal or if either one of the 
            files ends.
 */
char* difference(const char* file1, const char* file2) 
{
    char string1[1000];
    char string2[1000];
    char dash[] = {"----\n"}; 
	FILE *fp1 = fopen(file1,"r");
    FILE *fp2 = fopen(file2,"r");
    char* ret1 = fgets(string1,sizeof(string1),fp1);
    char* ret2 = fgets(string2,sizeof(string2),fp2);
    if (fp1 == NULL)
    {
        return NULL;
    }
    if (fp2 == NULL)
    {
        return NULL;
    }

    while (ret1 != NULL && ret2 != NULL)
    {
        if (strcmp(ret1,ret2))
        {
            char* dmem = malloc(sizeof(char*)*(strlen(string1)+strlen(string2)+strlen(dash)+1));
            strcpy(dmem,string1);
            strcat(dmem,dash);
            strcat(dmem,string2);
            strcat(dmem,"\0");
            fclose(fp1);
            fclose(fp2);
            return dmem;
        }
        else
        {
            ret1 = fgets(string1,sizeof(string1),fp1);
            ret2 = fgets(string2,sizeof(string2),fp2);
        }
    }
    return NULL;
    
}
