#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *vystup = fopen("output.txt", "w");

    for (int i = 1; i < argc; i++)
    {
        FILE *vstup = fopen(argv[i], "r");

        if (vstup != NULL)
        {
            int pocet = 0;
            char x;

            while (fscanf(vstup, "%c", &x) != EOF)
            {
                pocet++;
            }

            fclose(vstup);

            fprintf(vystup, "Soubor %s obsahuje %i znaku\n", argv[i], pocet);
        }
        else
        {
            fprintf(stderr, "Soubor %s se nepodarilo otevrit\n", argv[i]);
        }
    }

    fclose(vystup);

    return 0;
}