#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 101 // Maximalni delka jmena/cisla v kontaktu je 100 (101 prvek pole pro '\0')

char char_to_digit(char ch);                                             // Funkce pro prevod znaku na cislo
bool matches(const char *text, const char *pattern, int pattern_length); // Funkce pro hledani shody argumentu s kontaktem
void cut_nl(char *s);
bool test_lentgh;

int main(int argc, char *argv[])
{

    if (argc > 2)
    {
        fprintf(stderr, "Prilis mnoho argumentu\n");
        return 1;
    }

    char *argv_num = (argc == 1) ? " " : argv[1];
    int argv_length = strlen(argv_num);

    char name[MAX_LENGTH] = {0};
    char number[MAX_LENGTH] = {0};
    char control_line[MAX_LENGTH] = {0};
    bool found_matches = false;

    while (fgets(name, MAX_LENGTH, stdin) != NULL)
    {
        size_t len_name = strlen(name);
        if(len_name > 0 && name[len_name-1] != '\n'){
            fprintf(stderr, "Prilis dlouhy radek\n");
            return 2;
        }
        cut_nl(name);

        if (fgets(number, MAX_LENGTH, stdin) == NULL)
        {
            fprintf(stderr, "Invalid input format\n");
            break;
        }

        size_t len_num = strlen(number);

        if(len_num > 0 && number[len_num-1] != '\n'){
            fprintf(stderr, "Prilis dlouhy radek\n");
            return 2;
        }

        cut_nl(number);


        if (argc > 1)
        {

            
            for (size_t i = 0; i < len_name; i++)
            {
                control_line[i] = char_to_digit(name[i]);
            }

            control_line[len_name] = '\0';

            if (matches(control_line, argv_num, argv_length))
            {
                printf("%s, %s\n", name, number);
                found_matches = true;

                continue;
            }
            size_t len_num = strlen(number);
            for (size_t i = 0; i < len_num; i++)
            {
                control_line[i] = char_to_digit(number[i]);
            }

            control_line[len_num] = '\0';

            if (matches(control_line, argv_num, argv_length))
            {
                found_matches = true;
                printf("%s, %s\n", name, number);

                continue;
            }
        }
        else
        {
            printf("%s, %s\n", name, number);
            found_matches = true;
        }
    }

    if (!found_matches)
        printf("Not found\n");
    return 0;
}

char char_to_digit(char ch)
{
    ch = tolower((unsigned char)ch); // sjednotit na mala pismena

    switch (ch)
    {
    case 'a':
    case 'b':
    case 'c':
        return '2';
    case 'd':
    case 'e':
    case 'f':
        return '3';
    case 'g':
    case 'h':
    case 'i':
        return '4';
    case 'j':
    case 'k':
    case 'l':
        return '5';
    case 'm':
    case 'n':
    case 'o':
        return '6';
    case 'p':
    case 'q':
    case 'r':
    case 's':
        return '7';
    case 't':
    case 'u':
    case 'v':
        return '8';
    case 'w':
    case 'x':
    case 'y':
    case 'z':
        return '9';
    case '+':
        return '0';
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return ch; // cislice se mapuje sama na sebe
    default:
        return '?'; // nebo treba nejaky specialni znak / chyba
    }
}

bool matches(const char *text, const char *pattern, int pattern_length)
{
    // projdeme vsechny mozne startovni pozice v textu
    for (int i = 0; text[i] != '\0'; i++)
    {
        int j = 0;

        // zkousime, jestli od pozice i sedi cely pattern
        while (j < pattern_length &&
               text[i + j] != '\0' &&
               text[i + j] == pattern[j])
        {
            j++;
        }

        // pokud jsme dosli az na konec patternu, mame shodu
        if (j == pattern_length)
            return true;
    }

    return false;
}

void cut_nl(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '\n')
        {
            s[i] = '\0';
            break;
        }
        i++;
    }
}

