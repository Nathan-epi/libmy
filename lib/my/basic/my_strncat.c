/*
** EPITECH PROJECT, 2026
** my_strncat
** File description:
** A function that concatenates n characters of the src
** string to the end of the dest string.
*/

#include "library.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    for (i = 0; dest[i]; i++);
    for (j = 0; j < nb && src[j]; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
