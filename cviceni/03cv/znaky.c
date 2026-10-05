#include <stdio.h>
#include <ctype.h>

int main()
{
    char a, b;

    scanf("%c %c", &a, &b);

    if (isdigit(a))
        printf("Prvni znak je cislice\n");

    if (isalpha(a) || isalpha(b))
        printf("Alespon jeden ze znaku je pismeno\n");

    if (!isdigit(b) && !isalpha(b))
        printf("Druhy znak neni ani cislice ani pismeno\n");

    if (isalpha(a) && isalpha(b) &&
        tolower(a) == tolower(b))
        printf("Oba znaky jsou stejne pismeno, bez ohledu na velikost\n");

    return 0;
}