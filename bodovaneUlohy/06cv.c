//== knihovny ==
#include <stdio.h>
#include <math.h>

//== nove datove typy ==
typedef struct Sbod // definujeme strukturu jmenem "Sbod"
{                   // se dvema polozkami
    float x;        // polozka typu "float" jmenem "x"
    float y;        // polozka typu "float" jmenem "y"
} bod;              // deklarujeme jeji datovy typ "bod"

//== deklarace funkci ==
float vzdalenost(bod A, bod B);
float prumernaVzdalenost(int delka, bod pole[]);
void stredMnoziny(int delka, bod pole[], bod *S);
bod *nejblizsiBod(int delka, bod pole[], bod S);

//== definice funkci ==
float vzdalenost(bod A, bod B) // definice funkce "vzdalenost"
{
    float dx = A.x - B.x;           // pocitame rozdil na ose X
    float dy = A.y - B.y;           // pocitame rozdil na ose Y
    return sqrt(dx * dx + dy * dy); // pocitame Pythagorovu vetu
}

float prumernaVzdalenost(int delka, bod pole[])
{
    float prumer = 0;
    float count = 0;
    // zadny bod nesmim pocitat sam se sebou
    for (int i = 0; i < delka; i++)
    {
        for (int j = i + 1; j < delka; j++)
        {
            prumer += vzdalenost(pole[i], pole[j]);
            count++;
        }
    }

    return prumer / count;
}

void stredMnoziny(int delka, bod pole[], bod *S) // definice
{
    S->x = 0;
    S->y = 0;
    
    for (int i = 0; i < delka; i++)
    {
        S->x += pole[i].x;
        S->y += pole[i].y;
    }

    S->x /= delka;
    S->y /= delka;
}

bod *nejblizsiBod(int delka, bod pole[], bod S) // definice
{
    float nejblizsi = vzdalenost(S, pole[0]);
    bod *nejblizsiBod = &pole[0];

    for (int i = 1; i < delka; i++)
    {
        if (vzdalenost(S, pole[i]) < nejblizsi) {
         nejblizsiBod = &pole[i];
         nejblizsi = vzdalenost(S, pole[i]);
        } 
            
    }
    return nejblizsiBod;
}

int main() // zacatek programu
{
    bod M1[4] = {{0.0, 0.0}, {1.0, 1.0}, {2.0, 2.0}, {2.0, 0.0}}; // prvni mnozina
    bod M2[4] = {{0.0, 0.0}, {1.0, 3.0}, {3.0, 2.0}, {3.0, 0.0}}; // druha mnozina
    float d;                                                      // prumerna vzdalensot
    bod S;                                                        // stred mnoziny
    bod *N;                                                       // ukazatel na nejblizsi bod

    printf("Prvni mnozina:\n");
    d = prumernaVzdalenost(4, M1);                           // pocitame prumernou vzdalenost
    printf("Prumerna vzdalenost je %f\n", d);                // vypis
    stredMnoziny(4, M1, &S);                                 // pocitame souradnice stredu
    printf("Souradnice stredu  (%.2f, %.2f)\n", S.x, S.y);   // vypis
    N = nejblizsiBod(4, M1, S);                              // zjistujeme neblizsi bod
    printf("Nejblizsi prvek je (%.2f, %.2f)\n", N->x, N->y); // vypis

    printf("Druha mnozina:\n");
    d = prumernaVzdalenost(4, M2);                           // pocitame prumernou vzdalenost
    printf("Prumerna vzdalenost je %f\n", d);                // vypis
    stredMnoziny(4, M2, &S);                                 // pocitame souradnice stredu
    printf("Souradnice stredu  (%.2f, %.2f)\n", S.x, S.y);   // vypis
    N = nejblizsiBod(4, M2, S);                              // zjistujeme neblizsi bod
    printf("Nejblizsi prvek je (%.2f, %.2f)\n", N->x, N->y); // vypis

    return 0; // konec programu
}