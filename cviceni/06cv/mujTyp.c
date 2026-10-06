#include <stdio.h>

typedef struct
{
    char znak;
    int cislo;
} mujTyp;

int main()
{
    int pole[5] = {10, 20, 30, 40, 50};

    printf("Adresa pole: %p\n", (void *)pole);
    printf("Velikost pole: %zu B\n\n", sizeof(pole));

    for (int i = 0; i < 5; i++)
    {
        printf("index: %d, adresa: %p, velikost: %zu B\n",
               i, (void *)&pole[i], sizeof(pole[i]));
    }

    printf("\n");

    mujTyp promenna;

    printf("Velikost promenne: %zu B\n", sizeof(promenna));
    printf("Velikost znaku: %zu B\n", sizeof(promenna.znak));
    printf("Velikost cisla: %zu B\n", sizeof(promenna.cislo));

    return 0;
}