# include <stdio.h>
# include "source.h"
double fracsum(int x, int y, int a, int b)
{  
    double x1 = x;
    double y1 = y;

    double x2 = a;
    double y2 = b;
	
    double frac1 = x1/y1;
    double frac2 = x2/y2;

	double result = frac1 + frac2;

	return result;
}