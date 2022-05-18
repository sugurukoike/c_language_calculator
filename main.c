#include "calc.h"

int check_invalid_number(char *argv);
int check_invalid_operator(char *argv);

int main(int argc, char **argv)
{
    float result;
    float num;
    int num_index;
    int ope_index;

    if (argc % 2 != 0)
    {
        printf("Error: Insufficient number of arguments.\n");
        printf("Examples of Use: 10 + 20\n");
        return (1);
    }

    num_index = 1;
    while (num_index < argc)
    {
        if (check_invalid_number(argv[num_index]))
        {
            printf("Error: The number of position %d is invalid number.\n", num_index / 2 + 1);
            return (1);
        }
        num_index += 2;
    }

    ope_index = 2;
    while (ope_index < argc - 1)
    {
        if (check_invalid_operator(argv[ope_index]))
        {
            printf("Error: The operator of position %d is invalid.\n", ope_index / 2);
            return (1);
        }
        ope_index += 2;
    }

    num_index = 3;
    ope_index = 2;
    while (num_index < argc)
    {
        if (*argv[num_index] == '0' && *argv[ope_index] == '/')
        {
            printf("Error: Cannot be divided by zero.\n");
            printf("Fix number of potion %d or operator of potion %d.\n", num_index / 2 + 1, ope_index / 2);
            return (1);
        }
        num_index += 2;
        ope_index += 2;
    }

    num_index = 3;
    ope_index = 2;
    result = atof(argv[1]);
    while (num_index < argc)
    {
        num = atof(argv[num_index]);
        result = solve(result, num, *argv[ope_index]);
        num_index += 2;
        ope_index += 2;
    }
    printf("result is %f\n", result);
}

int check_invalid_number(char *argv)
{
    while (*argv != '\0')
    {
        if (*argv < '0' || '9' < *argv)
            return (1);
        argv++;
    }
    return (0);
}

int check_invalid_operator(char *argv)
{
    if (*argv != '+' && *argv != '-' && *argv != 'x' && *argv != '/' || strlen(argv) != 1)
        return (1);
    return (0);
}
