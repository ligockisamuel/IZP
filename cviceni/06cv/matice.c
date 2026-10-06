//== knihovny ==
#include <stdio.h>

//== deklarace funkci ==
void vypisVektor(int delka, int vektor[]);
void vypisMatici(int delka, int matice[delka][delka]);
void vymenCisla(int *a, int *b);
void obratVektor(int delka, int vektor[]);
void vypisNadVedlejsi(int delka, int matice[delka][delka]);
void transponujMatici(int delka, int matice[delka][delka]);

//== definice funkci ==

void vypisVektor(int delka, int vektor[])
{
    for (int i = 0; i < delka; i++) // pro vsechny prvky pole
    {
        printf("%i ", vektor[i]); // vypis prvek pole
    }
    printf("\n"); // vypis konec radku
}

void vypisMatici(int delka, int matice[delka][delka])
{
    for (int i = 0; i < delka; i++) // pro kazdy radek
    {
        for (int j = 0; j < delka; j++) // pro kazdy sloupec
        {
            printf("%2i ", matice[i][j]); // vypis prvek pole
        }
        printf("\n"); // vypis konec radku
    }
}

void vymenCisla(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void obratVektor(int delka, int vektor[])
{
    int cislo;
    int count = 0;

    for (int i = 0; i < delka / 2; i++)
    {
        cislo = vektor[delka - 1 - count];
        vektor[delka - 1 - count] = vektor[i];
        vektor[i] = cislo;
        count++;
    }
}

void vypisNadVedlejsi(int delka, int matice[delka][delka])
{
    int count = 0;

    for (int i = 0; i < delka - 1; i++)
    {

        for (int j = 0; j < delka - count - 1; j++)
        {
            printf("%d ", matice[i][j]);
        }
        count++;
        printf("\n");
    }
    printf("\n");
}


    void transponujMatici(int delka, int matice[delka][delka])
    {
        for (int i = 0; i < delka; i++)
        {
            for (int j = i + 1; j < delka; j++)
            {
                int temp = matice[i][j];
                matice[i][j] = matice[j][i];
                matice[j][i] = temp;
            }
        }
    }


int main() // zacatek programu
{
    int vektor[5] = {1, 2, 3, 4, 5}; // jedno-rozmerne pole (vektor)
    printf("Puvodni vektor:\n");
    vypisVektor(5, vektor); // vypis

    obratVektor(5, vektor); // obracime vektor
    printf("Obraceny vektor:\n");
    vypisVektor(5, vektor); // vypis

    int matice[5][5] = {}; // dvou-rozmerne pole (matice)

    for (int i = 0; i < 5; i++) // pro kazdy radek
    {
        for (int j = 0; j < 5; j++) // pro kazdy sloupec
        {
            matice[i][j] = i * 5 + j; // matici naplnime cisly
        }
    }

    printf("Puvodni matice:\n");
    vypisMatici(5, matice); // vypis

    printf("Cisla nad vedlejsi diagonalou:\n");
    vypisNadVedlejsi(5, matice); // vypisujeme cisla nad diagonalou

    transponujMatici(5, matice); // transponujeme matici
    printf("Transponovana matice:\n");
    vypisMatici(5, matice); // vypis

    return 0; // konec programu
}