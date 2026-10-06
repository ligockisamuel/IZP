#include <stdio.h>
#include <math.h>

typedef struct Sbod
{
    float x;
    float y;
} bod;

//TODO vlozeni knihoven a vytvoreni datoveho typu bod
typedef struct Strojuhelnik //vytvarime strukturu
{ //"Strojuhelnik" s polozkami
bod A; // bod "A"
bod B; // bod "B"
bod C; // bod "C"
} trojuhelnik; //struktura je typu "trojuhelnik"

float obvod(trojuhelnik T);
float obsah(trojuhelnik T);
bod teziste(trojuhelnik T);

int main() //zacatek programu
{
trojuhelnik T; //vytvarime trojuhelnik jmenem "T"
scanf("%f %f", &T.A.x, &T.A.y); //nacitame souradnice vrcholu "A"
scanf("%f %f", &T.B.x, &T.B.y); //nacitame souradnice vrcholu "B"
scanf("%f %f", &T.C.x, &T.C.y); //nacitame souradnice vrcholu "C"
printf("Obvod = %.3f\n", obvod(T)); //pocitame a vypisujeme obvod
printf("Obsah = %.3f\n", obsah(T)); //pocitame a vypisujeme obsah
bod S = teziste(T); //pocitame teziste
printf("Teziste = (%.3f, %.3f)\n", S.x, S.y); //vypisujeme teziste
return 0; //konec programu
}

float obvod(trojuhelnik T) {
    float A = sqrt(pow(T.B.x-T.A.x,2.0) + pow(T.B.y-T.A.y,2.0));
    float B = sqrt(pow(T.C.x-T.B.x,2.0) + pow(T.C.y-T.B.y,2.0));
    float C = sqrt(pow(T.C.x-T.A.x,2.0) + pow(T.C.y-T.A.y,2.0));
    
    return A+B+C;
}
float obsah(trojuhelnik T){
    float s = obvod(T)/2;
    float A = sqrt(pow(T.B.x-T.A.x,2.0) + pow(T.B.y-T.A.y,2.0));
    float B = sqrt(pow(T.C.x-T.B.x,2.0) + pow(T.C.y-T.B.y,2.0));
    float C = sqrt(pow(T.C.x-T.A.x,2.0) + pow(T.C.y-T.A.y,2.0));

    return sqrt(s*(s-A)*(s-B)*(s-C));


}
bod teziste(trojuhelnik T) {
    bod teziste;

    teziste.x = (T.A.x+T.B.x+T.C.x)/3;
    teziste.y = (T.A.y+T.B.y+T.C.y)/3;
    
    return teziste;
}
