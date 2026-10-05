#include <stdio.h>

int main()
{
    char str[1000];
    int i = 0;

    printf("Enter a C program (end with #):\n");

    while ((str[i] = getchar()) != '#')
    {
        i++;
    }
    str[i] = '\0';

    printf("\nExtracted Comments:\n");

    for (i = 0; str[i] != '\0'; i++)
    {
        // Single-line comment
        if (str[i] == '/' && str[i + 1] == '/')
        {
            printf("Single-line comment: ");

            i += 2;
            while (str[i] != '\n' && str[i] != '\0')
            {
                putchar(str[i]);
                i++;
            }
            printf("\n");
        }

        // Multi-line comment
        else if (str[i] == '/' && str[i + 1] == '*')
        {
            printf("Multi-line comment: ");

            i += 2;
            while (!(str[i] == '*' && str[i + 1] == '/') &&
                   str[i] != '\0')
            {
                putchar(str[i]);
                i++;
            }

            printf("\n");
            i++;
        }
    }

    return 0;
}