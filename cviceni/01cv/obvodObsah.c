#include <stdio.h>

int main(void)
{
    int a;
    int b;
    printf("Zadejte hodnotu a: \n");
    scanf("%d", &a);
    printf("Zadejte hodnotu b: \n");
    scanf("%d", &b);
    
    
    printf("Obvod = %d\nObsah = %d\n", 2*(a+b), a*b);
    return 0;
}