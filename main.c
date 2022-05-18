#include "calc.h"

bool check_invalid_argv(char *argv);

int main(int argc, char **argv)
{
    float num1;
    float num2;
    float result;

    if (argc != 4)
    {
        printf("Error: Insufficient number of arguments.\n");
        printf("Sorry, I am still only up to two numbers.\n");
        printf("Examples of Use: 10 + 20\n");
        return (1);
    }
    if (check_invalid_argv(argv[1]) && check_invalid_argv(argv[3]))
    {
        printf("Error: The first number and second number are invalid number.\n");
        return (1);
    }
    if (check_invalid_argv(argv[1]))
    {
        printf("Error: The first number is invalid number.\n");
        return (1);
    }
    if (check_invalid_argv(argv[3]))
    {
        printf("Error: The second number is invalid number.\n");
        return (1);
    }
    if (*argv[2] != '+' && *argv[2] != '-' && *argv[2] != 'x' && *argv[2] != '/' || strlen(argv[2]) != 1)
    {
        printf("Error: Invalid operator.\n");
        printf("Can use operator: +  -  x  /\n");
        return (1);
    }
    if (*argv[2] == '/' && *argv[3] == '0')
    {
        printf("Error: Cannot be divided by zero.\n");
        return (1);
    }

    printf("%s\n", argv[2]);

    num1 = atof(argv[1]);
    num2 = atof(argv[3]);
    result = solve(num1, num2, *argv[2]);
    printf("result is %f\n", result);

    return (0);
}

bool check_invalid_argv(char *argv)
{
    while (*argv != '\0')
    {
        if (*argv <= '0' || '9' <= *argv)
            return (true);
        argv++;
    }
    return (false);
}
