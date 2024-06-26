#include <math.h>
#include <stdio.h>
double vectorlength(double x, double y, double z)
{
    double x_comp = x;
    double y_comp = y;
    double z_comp = z;
    double length = sqrt(x_comp*x_comp + y_comp*y_comp + z_comp*z_comp);
    return length;
}




