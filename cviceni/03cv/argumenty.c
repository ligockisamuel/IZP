#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Nedostatek argumentu\n");
        return 1;
    }

    float max = atoi(argv[1]);
    float avg = 0;
    float pomocna;

    for (int i = 1; i < argc; i++)
    {
        pomocna = atoi(argv[i]);
        if (pomocna > max)
            max = pomocna;
        avg+=pomocna;
    }

    printf("Maximum je: %.1f, prumer je: %.1f", max, avg / (argc - 1));
    return 0;
}