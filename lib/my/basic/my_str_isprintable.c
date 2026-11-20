/*
** EPITECH PROJECT, 2026
** my_str_isprintable
** File description:
** A function that returns 1 if the string only contains printable
** characters and 0 if other type of character.
*/

#include "library.h"

// Return `1` if all character of the char* is only printable character
int my_str_isprintable(char const *str)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < my_strlen(str); i++) {
        if (str[i] >= ' ' && str[i] <= '~')
            j++;
    }
    if (j == i)
        return true;
    return false;
}
