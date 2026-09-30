#include <stdio.h>
#include <string.h>

int main()
{
    char statement[200];
    int i, compound = 0;

    printf("Enter a statement: ");
    fgets(statement, sizeof(statement), stdin);

    for (i = 0; statement[i] != '\0'; i++)
    {
        if ((statement[i] == '&' && statement[i + 1] == '&') ||
            (statement[i] == '|' && statement[i + 1] == '|'))
        {
            compound = 1;
            break;
        }
    }

    if (compound)
        printf("The given statement is a Compound Statement.\n");
    else
        printf("The given statement is a Simple Statement.\n");

    return 0;
}