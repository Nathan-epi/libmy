/*
** EPITECH PROJECT, 2026
** my_strncpy
** File description:
** A function that copies n characters from a string into another.
*/

#include "library.h"

// Copie n characters from a string into an another
char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    if (n > my_strlen(src))
        dest[i] = '\0';
    return dest;
}
