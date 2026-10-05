#include <stdio.h>

typedef struct Sbod
{
    float x;
    float y;
} bod;

typedef struct Ssouradnice
{
    int radek;
    int sloupec;
} souradnice;

int cisloNaSouradnicich(int n, int pole[n][n], souradnice kde);
souradnice souradniceCisla(int n, int pole[n][n], int cislo);

int main()
{
    int arr[5][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9},
        {10, 11, 12, 13, 14},
        {15, 16, 17, 18, 19},
        {20, 21, 22, 23, 24}
    };

    int cislo;
    souradnice kde;

    kde.radek = 3;
    kde.sloupec = 2;

    cislo = cisloNaSouradnicich(5, arr, kde);

    printf("Na souradnicich [%i][%i] je cislo %i\n",
           kde.radek, kde.sloupec, cislo);

    kde.radek = 0;
    kde.sloupec = 5;

    cislo = cisloNaSouradnicich(5, arr, kde);

    printf("Na souradnicich [%i][%i] je cislo %i\n",
           kde.radek, kde.sloupec, cislo);

    cislo = 14;

    kde = souradniceCisla(5, arr, cislo);

    printf("Cislo %i je na souradnicich [%i][%i]\n",
           cislo, kde.radek, kde.sloupec);

    cislo = 30;

    kde = souradniceCisla(5, arr, cislo);

    printf("Cislo %i je na souradnicich [%i][%i]\n",
           cislo, kde.radek, kde.sloupec);

    return 0;
}

int cisloNaSouradnicich(int n, int pole[n][n], souradnice kde)
{
    if (kde.radek >= 0 && kde.radek < n &&
        kde.sloupec >= 0 && kde.sloupec < n)
    {
        return pole[kde.radek][kde.sloupec];
    }

    return -1;
}

souradnice souradniceCisla(int n, int pole[n][n], int cislo)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (pole[i][j] == cislo)
            {
                souradnice kde;

                kde.radek = i;
                kde.sloupec = j;

                return kde;
            }
        }
    }

    souradnice kde;

    kde.radek = -1;
    kde.sloupec = -1;

    return kde;
}