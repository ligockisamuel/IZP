#include <stdio.h>

int main()
{

    float x[5];
    float indexMin = 0;

    for (int i = 0; i < 5; i++)
    {
        scanf("%f", &x[i]);
    }

    float max = x[0];
    float min = x[0];

    for (int i = 4; i > 0; i--)
    {

        if (x[i] < min)
        {
            indexMin = i;
            min = x[i];
        }

        else if (x[i] > max)
        {
            max = x[i];
        }
    }

    printf("Hodnota maxima:%.1f \n", max);
    printf("Index minima:%.1f \n", indexMin);

    for (int i = 4; i > 0; i--)
    {
        printf("%.1f ", x[i]);
    }
    printf("\n");

    return 0;
}