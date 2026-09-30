/*
** EPITECH PROJECT, 2026
** my_strcpy
** File description:
** A function that copies a string into another.
*/

#include "library.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(src);

    for (i = 0; i < len; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
