#include <stdio.h>
#include <ctype.h>
int main()
{
    int pismena = 0;
    int cislice = 0;
    int ostatni = 0;
    
    char znak;

    while (scanf("%c", &znak) != EOF)
    {
       if(isalpha(znak)) pismena++;
       if(isdigit(znak)) cislice++;
       if(!isalnum(znak)) ostatni++;
    }
    printf("%i pismen\n", pismena);
    printf("%i cislic\n", cislice);
    printf("%i ostatnich znaku\n", ostatni);
    return 0;
}