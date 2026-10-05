#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;
    int insideTag = 0;

    fp = fopen("sample.html", "r");

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    printf("HTML Tags found in the file:\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '<')
        {
            insideTag = 1;
            printf("<");
        }
        else if (ch == '>' && insideTag)
        {
            printf(">");
            printf("\n");
            insideTag = 0;
        }
        else if (insideTag)
        {
            printf("%c", ch);
        }
    }

    fclose(fp);

    return 0;
}
