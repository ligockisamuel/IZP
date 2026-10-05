#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char pole[101];
    int delka;
    int pocMalych = 0;
    int pocVelkych = 0;

    scanf("%100s", pole);

    delka = strlen(pole);

    for (int i = 0 ; i < delka; i++)
    {
        if (isupper(pole[i]))
            pocVelkych++;
        if (islower(pole[i]))
            pocMalych++;
        if (!isupper(pole[i]) && !islower(pole[i]))
            pole[i] = '-';
    }

    printf("%s obsahuje %d malych a %d velkych pismen\n", pole, pocMalych, pocVelkych);

    return 0;
}