#include "calc.h"

float solve(float num1, float num2, char ope)
{
    float result;

    result = 0;
    if (ope == '+')
        result = calc_add(num1, num2);
    else if (ope == '-')
        result = calc_sub(num1, num2);
    else if (ope == 'x')
        result = calc_mul(num1, num2);
    else if (ope == '/')
        result = calc_div(num1, num2);
    return (result);
}
