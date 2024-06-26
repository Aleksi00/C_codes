#include "source.h"

#include <math.h>
#include <stdio.h>

void simple_math(void)
{
    float number1;
    float number2;
    float result;
    char operand;
    
    scanf("%f %c %f", &number1, &operand, &number2);
    
    if (operand =='+')
    {
        result = number1 + number2;
        printf("%0.1f\n", result);
    }
    
    else if (number2 == 0)
    {
        printf("ERR\n");
    }
    
    else if (operand == '-')
    {
        result = number1 - number2;
        printf("%0.1f\n", result);
    }
    
    else if (operand =='*')
    {
        result = number1 * number2;
        printf("%0.1f\n", result);
    }
    
    else if (operand == '/')
    {
        result = number1 / number2;
        printf("%0.1f\n", result);
    }
    

    else
    {
        printf("ERR\n");
    }

}