#include <stdio.h>
#include <stdbool.h>

int minimum(int a, int b);
void vypisPole(int delka, int pole[]);
int minimumPole(int delka, int pole[]);
bool vsechnaKladna(int delka, int pole[]);

int main()
{

    int x = 10, y = 20;
    printf("x = %i\n", x);
    printf("y = %i\n", y);
    printf("Minimum z X a Y je %i\n\n", minimum(x, y));
    int pole[5] = {4, 3, 5, 1, 2};
    printf("Pole obsahuje cisla: ");
    vypisPole(5, pole);
    printf("Minimum z pole je %i\n", minimumPole(5, pole));
    if (vsechnaKladna(5, pole))
        printf("Vsechna cisla v poli jsou kladna\n");
    else
        printf("Alespon jedno cislo v poli neni kladne\n");
    return 0;
}

int minimum(int a, int b)
{

    return (a >= b) ? a : b;
}
void vypisPole(int delka, int pole[])
{
    for (int i = 0; i < delka; i++)
    {
        printf("%d ", pole[i]);
    }
    printf("\n");
}
int minimumPole(int delka, int pole[])
{

    int minimum = pole[0];

    for (int i = 1; i < delka; i++)
    {
        if (pole[i] < minimum)
            minimum = pole[i];
    }
    return minimum;
}
bool vsechnaKladna(int delka, int pole[])
{
    for (int i = 0; i < delka; i++)
    {
        if (pole[i] < 0)
            return false;
    }
    return true;
}