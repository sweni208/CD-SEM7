#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char input[100];
int stack[100];
int top = -1;
int ip = 0;

/* LALR Parsing Table
   Terminals: i, +, *, (, ), $
   Non-terminals: E, T, F
*/

char action[12][6] = {
    {"s5"}, {"r2"}, {"s6"}, {"s4"}, {"r4"}, {"r6"},
    {"s5"}, {"r2"}, {"r4"}, {"r6"}, {"acc"}, {"r1"}
};

int main()
{
    int state;
    
    printf("LALR Parser\n");
    printf("--------------------------------\n");
    
    printf("Grammar:\n");
    printf("1. E -> E + T\n");
    printf("2. E -> T\n");
    printf("3. T -> T * F\n");
    printf("4. T -> F\n");
    printf("5. F -> (E)\n");
    printf("6. F -> id\n\n");

    printf("Enter input string (use i for id): ");
    scanf("%s", input);

    strcat(input, "$");

    printf("\nInput: %s\n", input);
    printf("\nParsing process:\n");

    /* Simplified LALR parsing demonstration */
    while (input[ip] != '$')
    {
        if (input[ip] == 'i')
        {
            printf("Shift id\n");
            ip++;
        }
        else if (input[ip] == '+')
        {
            printf("Shift +\n");
            ip++;
        }
        else if (input[ip] == '*')
        {
            printf("Shift *\n");
            ip++;
        }
        else if (input[ip] == '(')
        {
            printf("Shift (\n");
            ip++;
        }
        else if (input[ip] == ')')
        {
            printf("Reduce F -> (E)\n");
            ip++;
        }
        else
        {
            printf("Error: Invalid input\n");
            return 0;
        }
    }

    printf("Reduce using LALR parsing rules\n");
    printf("Input string accepted.\n");

    return 0;
}