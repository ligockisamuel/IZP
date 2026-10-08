#include <stdio.h>

int rekurzeFibonacci(int n);
int cyklusFibonacci(int n);

int main(void)
{
    printf("Rekurze f(0) = %d\n", rekurzeFibonacci(0));
    printf("Rekurze f(1) = %d\n", rekurzeFibonacci(1));
    printf("Rekurze f(5) = %d\n", rekurzeFibonacci(5));
    printf("Rekurze f(10) = %d\n", rekurzeFibonacci(10));
    printf("Rekurze f(15) = %d\n", rekurzeFibonacci(15));

    printf("\n");

    printf("Cyklus f(0) = %d\n", cyklusFibonacci(0));
    printf("Cyklus f(1) = %d\n", cyklusFibonacci(1));
    printf("Cyklus f(5) = %d\n", cyklusFibonacci(5));
    printf("Cyklus f(10) = %d\n", cyklusFibonacci(10));
    printf("Cyklus f(15) = %d\n", cyklusFibonacci(15));

    return 0;
}

int rekurzeFibonacci(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return rekurzeFibonacci(n - 1) + rekurzeFibonacci(n - 2);
}

int cyklusFibonacci(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    int predchozi = 0;
    int aktualni = 1;

    for (int i = 2; i <= n; i++)
    {
        int dalsi = predchozi + aktualni;
        predchozi = aktualni;
        aktualni = dalsi;
    }

    return aktualni;
}