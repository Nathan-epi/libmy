/*
** EPITECH PROJECT, 2026
** my_strcapitalize
** File description:
** A function that capitalizes the first letter of each word.
*/

#include "library.h"

static void capitalize(char *str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z') {
        str[i] = str[i] - 32;
    }
}

// A function that capitalizes the first letter of each word.
char *my_strcapitalize(char *str)
{
    int i = 0;

    my_strlowcase(str);
    for (i = 0; str[i]; i++) {
        if (i == 0) {
            capitalize(str, i);
            continue;
        }
        if (str[i - 1] == ' ' || str[i - 1] == '+' || str[i - 1] == '-' ||
            str[i - 1] == ';' || str[i - 1] == ',' || str[i - 1] == '.' ||
            str[i - 1] == '=') {
            capitalize(str, i);
        }
    }
    return (str);
}
