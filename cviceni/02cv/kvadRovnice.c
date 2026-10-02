#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float x1, x2;

    printf("Nacti tri cisla\n");

    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    if(2*a == 0) {
    printf("Deleni nulou nelze!\n");
    return 1;    
    }
    
    float d = pow(b,2.0) - 4*a*c;

    if(d < 0) {
    printf("Odmocnina ze zaporneho cisla, rovnice nema reseni\n");
    return 2;    
    }

    x1 = (-b + sqrt(d)) / (2*a);
    x2 = (-b - sqrt(d)) / (2*a);

    printf("x1=%f x2=%f\n",x1,x2);

    return 0;
}
