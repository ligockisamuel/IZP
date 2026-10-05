#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Spatny pocet argumentu\n");
        return 1;
    }

    char string[11];

    if (scanf("%10s", string) != 1)
    {
        printf("Spatne nacitam retezec\n");
        return 2;
    };

    int delka = strlen(string);

    if (strcmp(argv[1], "tolower") == 0)
    {
        for (int i = 0; i < delka; i++)
        {
            printf("%c", tolower(string[i]));
        }
        printf("\n");
        return 0;
    }
    else if (strcmp(argv[1], "notalnum") == 0)
    {

        for (int i = 0; i < delka; i++)
        {
            if (!(isalnum(string[i])))
                printf("%c", string[i]);
        }
        printf("\n");
        return 0;
    }

    /*
    Palindrom je retezec ktery se cte stejne zleva doprava jako zprava doleva
    */

    else if (strcmp(argv[1], "palindrom") == 0)
    {

        /*
        Potrebuju procházet retezec a porovnávat prvni znak s poslednim,
        druhy s predposlednim...
        */

        int j = delka - 1;
        for (int i = 0; i < delka / 2; i++)
        {

            if (string[i] != string[j])
            {
                printf("%s neni palindrom\n", string);
                return 0;
            }
            j--;
        }
    }
    else
    {
        printf("Spatny argument\n");
        return 3;
    }
    printf("%s je palindrom\n", string);
    return 0;
}