#include <stdio.h>
#include <math.h>
#include "source.h"

void draw_triangle(unsigned int size)
{

     unsigned int i, j, k;
     scanf("%d", &size);
     scanf("%d", &size);

    for(i=size; i>=1; --i)
    {
        //printf(".");
        for(j=1; j<i; ++j)
        {
            printf(".");
        }
        
        for(k=0; k<size-i+1; ++k)
        {
            printf("#");
        }
        printf("\n");
    }
}


