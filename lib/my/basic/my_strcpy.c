/*
** EPITECH PROJECT, 2026
** my_strcpy
** File description:
** A function that copies a string into another.
*/

#include "library.h"

// A function that copies a string into another.
char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; i < my_strlen(src); i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
