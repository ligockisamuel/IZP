#include <stdio.h>

void minMax(int delka, int pole[], int *min, int *max);

int main()
{

    int pole[5];
    int min, max;

    for (int i = 0; i < 5; i++)
    {

        scanf("%d", &pole[i]);
    }

    minMax(5, pole, &min, &max);
    printf("Min:%d Max:%d\n", min, max);

    return 0;
}

void minMax(int delka, int pole[], int *min, int *max)
{
    int minimum = pole[0];
    int maximum = pole[0];

    for (int i = 1; i < delka; i++)
    {
        if (pole[i] < minimum)
        {
            minimum = pole[i];
        }

        else if (pole[i] > maximum)
        {
            maximum = pole[i];
        }
    }

    *min = minimum;
    *max = maximum;
}