/*
** EPITECH PROJECT, 2026
** my_str_isnum
** File description:
** A function that returns 1 if the string only contains numerical
** characters and 0 if other type of character.
*/

#include "library.h"

// Return `1` if all character of the char* is only numerical character
int my_str_isnum(char const *str)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < my_strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9')
            j++;
    }
    if (j == i)
        return true;
    return false;
}
