#include <stdio.h>
#include <stdbool.h>

bool jeVMnozine(int delka, int pole[], int cislo);
bool jeMnozina(int delka, int pole[]);
void vypisPrunik(int delkaA, int poleA[], int delkaB, int poleB[]);
void vypisSjednoceni(int delkaA, int poleA[], int delkaB, int poleB[]);

int main() // zacatek programu
{
    int poleA[4] = {1, 2, 3, 4};                    // prvni inicializovane pole
    int poleB[5] = {0, 2, 4, 6, 7};                 // druhe inicializovane pole
    if (jeMnozina(4, poleA))                        // overujeme ze poleA je mnozina
        printf("pole A je mnozina\n");              // pokud ano, vypis
    else                                            // jinak
        printf("pole A neni mnozina\n");            // pokud ne, vypis
    if (jeMnozina(5, poleB))                        // overujeme ze poleB je mnozina
        printf("pole B je mnozina\n");              // pokud ano, vypis
    else                                            // jinak
        printf("pole B neni mnozina\n");            // pokud ne, vypis
    if (jeMnozina(4, poleA) && jeMnozina(5, poleB)) // pokud obe jsou mnoziny
    {
        vypisPrunik(4, poleA, 5, poleB);     // vypisujeme jejich prunik
        vypisSjednoceni(4, poleA, 5, poleB); // vypisujeme jejich sjednoceni
    }
    return 0; // konec programu
}

bool jeVMnozine(int delka, int pole[], int cislo)
{
    for (int i = 0; i < delka; i++)
    {
        if (cislo == pole[i])
            return true;
    }

    return false;
}
bool jeMnozina(int delka, int pole[])
{
    for (int i = 0; i < delka / 2; i++)
    {
        for (int j = delka - 1; j > i; j--)
            if (pole[i] == pole[j])
                return false;
    }

    return true;
}
void vypisPrunik(int delkaA, int poleA[], int delkaB, int poleB[])
{

    printf("Prunik je: ");

    for (int i = 0; i < delkaA; i++)
    {
        
            if (jeVMnozine(delkaB, poleB, poleA[i]))
            {
                printf("%i ", poleA[i]);
                
            }
        
    }
    printf("\n");
}
void vypisSjednoceni(int delkaA, int poleA[], int delkaB, int poleB[])
{
    printf("Sjednoceni je: ");

    for (int i = 0; i < delkaA; i++)
    {
        printf("%i ", poleA[i]);
    }

    for (int i = 0; i < delkaB; i++)
    {
        if (!jeVMnozine(delkaA, poleA, poleB[i]))
        {
            printf("%i ", poleB[i]);
        }
    }
    printf("\n");
}
