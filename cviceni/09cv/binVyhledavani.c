//== knihovny ==
#include <stdio.h>

//== deklarace funkci == 
int binarniVyhledavani(int zacatek, int konec, int pole[], int cislo);

//== definice funkci == 
//implementuje algoritmus binarniho vyhledavani pomoci REKURZE
int binarniVyhledavani(int zacatek, int konec, int pole[], int cislo) 
{
    if (zacatek > konec)
        return -1;

    int stred = (zacatek + konec) / 2;

    if (pole[stred] == cislo)
        return stred;

    if (cislo < pole[stred])
        return binarniVyhledavani(zacatek, stred - 1, pole, cislo);

    return binarniVyhledavani(stred + 1, konec, pole, cislo);
}


//== hlavni funkce programu == 
int main(void)           
{   
    int a = 50;                           //prvni  hledane cislo
    int b = 20;                           //druhe hledane cislo
    int c = 60;                           //treti hledane cislo
    int d = 70;                           //ctvrte hledane cislo
    int pole[7] = {10,20,30,50,60,80,90}; //prohledavane pole (serazene)
    
    //volani funcke pro binarni vyhledavani
    printf("Cislo %i je na indexu %i\n",a, binarniVyhledavani(0,6,pole,a));
    printf("Cislo %i je na indexu %i\n",b, binarniVyhledavani(0,6,pole,b));
    printf("Cislo %i je na indexu %i\n",c, binarniVyhledavani(0,6,pole,c));
    printf("Cislo %i je na indexu %i\n",d, binarniVyhledavani(0,6,pole,d));

    return 0;        //konec programu
}