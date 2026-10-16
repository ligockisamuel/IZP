#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 102 // Maximalni delka jmena/cisla v kontaktu je 100 + '\n' + '\0'

// Vysledky funkce read_line
#define READ_OK 0
#define READ_EOF 1
#define READ_ERROR 2

char char_to_digit(char ch);                                                  // Prevod znaku na cislici
bool matches(const char *text, const char *pattern, int pattern_length);      // Hledani shody argumentu v textu
void cut_nl(char *s);                                                         // Odriznuti '\n'
bool check_args(int argc, char *argv[]);                                      // Kontrola argumentu programu
bool valid_name(const char *s);                                               // Kontrola jmena
bool valid_number(const char *s);                                             // Kontrola telefonniho cisla
int read_line(char *line, bool (*is_valid)(const char *), const char *error_msg); // Precte a zkontroluje jeden radek
bool text_matches(const char *text, const char *pattern, int pattern_length); // Prevede text na cislice a hleda shodu
bool contact_matches(const char *name, const char *number, const char *pattern, int pattern_length);

int main(int argc, char *argv[])
{
    if (!check_args(argc, argv))
        return 1;

    const char *pattern = (argc == 2) ? argv[1] : "";
    int pattern_length = strlen(pattern);

    char name[MAX_LENGTH] = {0};
    char number[MAX_LENGTH] = {0};
    bool found_matches = false;
    int status;

    while ((status = read_line(name, valid_name, "Invalid name")) == READ_OK)
    {
        status = read_line(number, valid_number, "Invalid phone number");
        if (status == READ_EOF)
        {
            fprintf(stderr, "Incomplete contact\n");
            return 2;
        }
        if (status == READ_ERROR)
            return 2;

        if (argc == 1 || contact_matches(name, number, pattern, pattern_length))
        {
            printf("%s, %s\n", name, number);
            found_matches = true;
        }
    }

    if (status == READ_ERROR)
        return 2;

    if (!found_matches)
        printf("Not found\n");
    return 0;
}

bool check_args(int argc, char *argv[])
{
    if (argc > 2)
    {
        fprintf(stderr, "Too many arguments\n");
        return false;
    }

    if (argc == 2)
    {
        int length = strlen(argv[1]);
        if (length == 0 || length > 100)
        {
            fprintf(stderr, "Invalid argument length\n");
            return false;
        }
        for (int i = 0; i < length; i++)
        {
            if (!isdigit((unsigned char)argv[1][i]))
            {
                fprintf(stderr, "Argument must contain only digits\n");
                return false;
            }
        }
    }
    return true;
}

int read_line(char *line, bool (*is_valid)(const char *), const char *error_msg)
{
    if (fgets(line, MAX_LENGTH, stdin) == NULL)
        return READ_EOF;

    size_t len = strlen(line);
    if (len > 0 && line[len - 1] != '\n')
    {
        fprintf(stderr, "Line too long\n");
        return READ_ERROR;
    }

    cut_nl(line);

    if (!is_valid(line))
    {
        fprintf(stderr, "%s\n", error_msg);
        return READ_ERROR;
    }
    return READ_OK;
}

// Delku (max 100) uz hlida read_line, zde se kontroluje neprazdnost a znaky
bool valid_name(const char *s)
{
    size_t len = strlen(s);

    if (len == 0)
        return false;

    for (size_t i = 0; i < len; i++)
    {
        unsigned char ch = (unsigned char)s[i];

        if (ch < 32 || ch > 126)
            return false;
    }

    return true;
}

// Cislice, pripadne jedno '+' na zacatku, za kterym nasleduji cislice
bool valid_number(const char *s)
{
    size_t len = strlen(s);

    if (len == 0)
        return false;

    size_t i = 0;

    if (s[0] == '+')
    {
        i = 1;

        if (i == len)
            return false;
    }

    for (; i < len; i++)
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }

    return true;
}

bool text_matches(const char *text, const char *pattern, int pattern_length)
{
    char control_line[MAX_LENGTH] = {0};
    size_t len = strlen(text);

    for (size_t i = 0; i < len; i++)
    {
        control_line[i] = char_to_digit(text[i]);
    }
    control_line[len] = '\0';

    return matches(control_line, pattern, pattern_length);
}

bool contact_matches(const char *name, const char *number, const char *pattern, int pattern_length)
{
    return text_matches(name, pattern, pattern_length) ||
           text_matches(number, pattern, pattern_length);
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
        return '?'; // znak, ktery zadna klavesa nezastupuje
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