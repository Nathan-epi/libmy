/*
** EPITECH PROJECT, 2026
** my_strcat
** File description:
** A function that concatenates two strings.
*/

#include "library.h"

// A function that concatenates two strings.
char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    for (i = 0; dest[i]; i++);
    for (j = 0; src[j]; j++) {
        dest[i] = src[j];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
