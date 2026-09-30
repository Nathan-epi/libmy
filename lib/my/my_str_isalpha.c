/*
** EPITECH PROJECT, 2026
** my_str_isalpha
** File description:
** A function that returns 1 if the string only contains alphabetical
** characters and 0 if other type of character.
*/

#include "library.h"

int my_str_isalpha(char const *str)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < my_strlen(str); i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z')) {
            j++;
        }
    }
    if (j == i)
        return 1;
    return 0;
}
