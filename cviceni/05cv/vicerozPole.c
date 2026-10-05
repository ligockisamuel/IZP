#include <stdio.h>

void vypisPole(int delka, int pole[delka][delka]);
void naplnPole(int delka, int pole[delka][delka]);
void vyhledejCislo(int delka, int pole[delka][delka], int cislo);
void vypisHlavni(int delka, int pole[delka][delka]);
void vypisVedlejsi(int delka, int pole[delka][delka]);

void vypisPole(int delka, int pole[delka][delka])
{
    for (int radek = 0; radek < delka; radek++)
    {
        for (int sloupec = 0; sloupec < delka; sloupec++)
        {
            printf("%2i ", pole[radek][sloupec]);
        }
        printf("\n");
    }
}

void naplnPole(int delka, int pole[delka][delka])
{
    int cislo = 0;

    for (int radek = 0; radek < delka; radek++)
    {
        for (int sloupec = 0; sloupec < delka; sloupec++)
        {
            pole[radek][sloupec] = cislo;
            cislo++;
        }
    }
}

void vyhledejCislo(int delka, int pole[delka][delka], int cislo)
{
    for (int radek = 0; radek < delka; radek++)
    {
        for (int sloupec = 0; sloupec < delka; sloupec++)
        {
            if (pole[radek][sloupec] == cislo)
            {
                printf("Cislo %i nalezeno na souradnicich [%i][%i]\n",
                       cislo, radek, sloupec);
                return;
            }
        }
    }

    printf("Cislo %i nebylo nalezeno\n", cislo);
}

void vypisHlavni(int delka, int pole[delka][delka])
{
    for (int i = 0; i < delka; i++)
    {
        printf("%i ", pole[i][i]);
    }

    printf("\n");
}

void vypisVedlejsi(int delka, int pole[delka][delka])
{
    for (int i = 0; i < delka; i++)
    {
        printf("%i ", pole[i][delka - 1 - i]);
    }

    printf("\n");
}

int main()
{
    int pole[5][5] = {};

    printf("Prazdne pole:\n");
    vypisPole(5, pole);

    naplnPole(5, pole);

    printf("Naplnene pole:\n");
    vypisPole(5, pole);

    vyhledejCislo(5, pole, 14);
    vyhledejCislo(5, pole, 30);

    printf("Hlavni diagonala:\n");
    vypisHlavni(5, pole);

    printf("Vedlejsi diagonala:\n");
    vypisVedlejsi(5, pole);

    return 0;
}