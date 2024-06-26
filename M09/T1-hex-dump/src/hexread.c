#include "hexread.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Prints the given file as hexdump.
 * 
 * \details The function outputs each byte in the file as a two character hexadecimal 
 *          number. 
 *
 *    - If a byte is less than ``0x10``, then the output should have ``0`` in 
 *      front of the number. 
 *    
 *    - Each line must have maximum of 16 hexadecimal numbers with a space between 
 *      them.
 * 
 *    - Only 16 hexadecimal numbers must be printed in one line and there should 
 *      be a space after the last value.After printing 16 hex values, the next 
 *      byte should be printed on the next line. 
 *
 *    - If the end-of-file indicator is set before a line ends, the dump should 
 *      end.
 * 
 * \param filename The name of the file to dump.
 * \return Returns the number of characters read or -1 if an error occurs when 
 *         reading the file.
 */
int file_to_hex(const char* filename) 
{
    int count = 1;
    int i = 0;
    unsigned char p[1];
    FILE *fp = fopen(filename, "r");
    int c = 1;

    if (fp == NULL)
    {
        return -1;
    }

    while (fread(p, c, c, fp))
    {
        if (i==15)
        {
            if (p[0] < 16)
            {
                printf("0%x \n", p[0]);
            }
            else
            {
                printf("%x \n", p[0]);
            }
            i = 0;
        }
        else
        {
            if (p[0] < 16)
            {
                printf("0%x ", p[0]);
            }
            else
            {
                printf("%x ", p[0]);
            }
            i++;
        }
        count++;
    }
    fclose(fp);
    return count;
}
