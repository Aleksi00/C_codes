#include <stdio.h>
#include <stdarg.h>
#include <string.h>


int myprint(const char *str, ...)
{
    va_list args;
    va_start(args,str);
    int retval = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '&')
        {
            printf("%c",str[i]);
        }
        else
        {
            printf("%d",va_arg(args,int));
            retval+=1;
        }
        
    }
    va_end(args);
    return retval;
}
