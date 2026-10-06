#include <stdio.h>

void vymenCisla(int* a, int* b);

int main() {

int a = 10;
int b = 20;
vymenCisla(&a,&b);

printf("A:%d B:%d\n", a,b);


    return 0;
}

void vymenCisla(int* a, int* b){
    int pom = *a;
    *a = *b;
    *b = pom;

}