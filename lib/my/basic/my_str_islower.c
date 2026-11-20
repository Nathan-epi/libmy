/*
** EPITECH PROJECT, 2026
** my_str_islower
** File description:
** A function that returns 1 if the string only contains lowercase
** alphabetical characters and 0 if other type of character.
*/

#include "library.h"

// Return `1` if all character of the char* is only
// alphabetical lowercase character
int my_str_islower(char const *str)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            j++;
    }
    if (j == i)
        return true;
    return false;
}
