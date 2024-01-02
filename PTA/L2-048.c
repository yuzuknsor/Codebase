#include <stdio.h>
#include <string.h>

int main()
{
    char str[81];
    int appeared[128] = {0};

    fgets(str, 81, stdin);

    str[strcspn(str, "\n")] = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        appeared[(int)str[i]] = 1;
    }

    for (int i = 0; i < 128; i++)
    {
        if (appeared[i])
        {
            printf("%c", i);
        }
    }
    printf("\n");

    return 0;
}