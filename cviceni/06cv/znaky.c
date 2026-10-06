//== knihovny ==
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//== deklarace funkci ==
char *najdiPrvniVelke(char str[]);
char *najdiPosledniVelke(char str[]);
void vymenZnaky(char *a, char *b);

//== definice funkci ==
char *najdiPrvniVelke(char str[])
{
    int delka = strlen(str);

    for (int i = 0; i < delka; i++)
    {
        if (isupper(str[i]))
            return &str[i];
    }

    return NULL;
}

char *najdiPosledniVelke(char str[])
{
    int delka = strlen(str);

    for (int i = delka - 1; i >= 0; i--)
    {
        if (isupper(str[i]))
            return &str[i];
           
    }
 return NULL;
   
}

void vymenZnaky(char *a, char *b)
{
    char pom = *a;
    *a = *b;
    *b = pom;
}

int main() // zacatek programu
{
    char strArr[3][14] = {"ABCD", "Hello, World!", "ahoj"}; // 2D pole znaku, incializovane pomoci textovych retezcu

    for (int i = 0; i < 3; i++) // cyklus pres vsechny retezce
    {
        char *prvni = najdiPrvniVelke(strArr[i]);       // ukazatel na prvni velke pismeno
        char *posledni = najdiPosledniVelke(strArr[i]); // ukazatel na posledni velke pismeno

        if (prvni != NULL && posledni != NULL) // pokud oba dva ukazatel jsou platne
        {
            vymenZnaky(prvni, posledni); // velka pismena spolu vymenime
            printf("%s\n", strArr[i]);   // vypisujeme upraveny retezec
        }
        else // jinak piseme chybove hlaseni
        {
            fprintf(stderr, "Retezec %s neobsahuje zadna velka pismena\n", strArr[i]); // chybovy vypis
        }
    }

    return 0; // konec programu
}