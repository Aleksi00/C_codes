#include "source.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void ascii_chart(char min, char max)
{
    int i;
    int k=0;
    char d = '?';

    for(i=min ; i<=max; ++i)
    {
        {
            if (isprint(i)!= 0)
                {
                    printf("%3d 0x%.2x %c", i, i, i);
                }
            else
                {
                    printf("%3d 0x%.2x %c", i, i, d);
                } 
        }
        k=k+1;
        if (k==4)
        {
            printf("\n");
            k=0;
        }
        else
        {
            printf("\t");
        }
    }
}
