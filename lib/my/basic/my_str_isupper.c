/*
** EPITECH PROJECT, 2026
** my_str_isupper
** File description:
** A function that returns 1 if the string only contains uppercase
** alphabetical characters and 0 if other type of character.
*/

#include "library.h"

// Return `1` if all character of the char* is only
// alphabetical uppercase character
int my_str_isupper(char const *str)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < my_strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            j++;
    }
    if (j == i)
        return true;
    return false;
}
