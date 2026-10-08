//== knihovny ==
#include <stdio.h>
#include <stdlib.h>

//== nove datove typy ==
typedef struct Svektor // deklarujeme datovy typ pro strukturu
{                      // jmenem "Svektor" se dvema polozkami
    int delka;         // pocet polozek
    int *pole;         // dynamicky alokovane pole
} vektor;              // jmeno tohoto typu je "vektor"

//== deklarace funkci ==
void vypisVektor(vektor *A);
void pridejPosledni(vektor *A, int cislo);
void odeberPosledni(vektor *A);
void odeberVsechny(vektor *A);
void pridejPrvni(vektor *A, int cislo);
void odeberIndex(vektor *A, int index);

//== definice funkci ==
void vypisVektor(vektor *A)
{
    printf("Vektor: ");                // Vypisujeme retezec "Vektor: "
    for (int i = 0; i < A->delka; i++) // pro vsechny prvky pole
    {
        printf("%i ", A->pole[i]); // vypisujeme hodnotu jednotlivych prvku
    }
    printf("\n"); // vypisujeme konec radku
}

void pridejPosledni(vektor *A, int cislo)
{
    int *y;
    y = realloc(A->pole, sizeof(int) * (A->delka + 1));
    if (y != NULL)
    {
        A->pole = y;
        A->delka++;
        A->pole[A->delka - 1] = cislo;
    }
}

void odeberPosledni(vektor *A)
{
    if (A->delka > 1)
    {
        int *y;
        y = realloc(A->pole, sizeof(int) * (A->delka - 1));
        if (y != NULL)
        {
            A->pole = y;
            A->delka--;
        }
    }
}

void odeberVsechny(vektor *A)
{
    free(A->pole);
    A->pole = NULL;
    A->delka = 0;
}

void pridejPrvni(vektor *A, int cislo)
{
    int *y;
    y = realloc(A->pole, sizeof(int) * (A->delka + 1));
    if (y != NULL)
    {
        A->pole = y;
        A->delka++;
        for (int i = A->delka - 1; i > 0; i--)
        {
            A->pole[i] = A->pole[i - 1];
        }
        A->pole[0] = cislo;
    }
}

void odeberIndex(vektor *A, int index)
{
    if (index >= 0 && index <= A->delka - 1)
    {
        for (int i = index; i < A->delka - 1; i++)
        {
            A->pole[i] = A->pole[i + 1];
        }
        A->delka--;
    }
}

int main() // zacatek programu
{
    vektor A = {0, NULL};
    vypisVektor(&A); // vytvarime vektor
                     //"A" je automaticky alokovana struktura
                     // obsahujici dynamicky alokovane pole
    pridejPosledni(&A, 10);
    vypisVektor(&A); // pridavame posledni prvek
    pridejPosledni(&A, 20);
    vypisVektor(&A); // pridavame posledni prvek
    pridejPosledni(&A, 30);
    vypisVektor(&A); // pridavame posledni prvek
    odeberPosledni(&A);
    vypisVektor(&A); // odebirame posledni prvek
    odeberVsechny(&A);
    vypisVektor(&A); // odebirame vsechny prvky
    odeberPosledni(&A);
    vypisVektor(&A); // odebirame neexistujici prvek
    pridejPrvni(&A, 40);
    vypisVektor(&A); // pridavame prvni prvek
    pridejPrvni(&A, 50);
    vypisVektor(&A); // pridavame prvni prvek
    pridejPrvni(&A, 60);
    vypisVektor(&A); // pridavame prvni prvek
    odeberIndex(&A, -1);
    vypisVektor(&A); // odebirame neexistujici prvek
    odeberIndex(&A, 3);
    vypisVektor(&A); // odebirame neexistujici prvek
    odeberIndex(&A, 1);
    vypisVektor(&A); // odebirame konkretni prvek
    odeberVsechny(&A);
    vypisVektor(&A); // odebirame vsechny prvky
    return 0;        // konec programu
}