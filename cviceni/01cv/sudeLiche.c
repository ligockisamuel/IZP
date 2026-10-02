#include <stdio.h>

int main(void)
{
    int a;
    printf("Zadejte cislo: \n");
    scanf("%d", &a);

    if(a >= 0 && a <= 10) printf("Cislo %d je v rozsahu\n", a);
    else printf("Cislo %d neni v rozsahu\n", a);

    if(a % 2 == 0) printf("Cislo %d je sude\n", a);
    else printf("Cislo %d je liche\n", a);

    
    return 0;
}