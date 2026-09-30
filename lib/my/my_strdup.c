/*
** EPITECH PROJECT, 2026
** my_strdup
** File description:
** A function that allocates memory and copies the string given.
*/

#include "library.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    char *str;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (i = 0; i < my_strlen(src); i++)
        str[i] = src[i];
    return str;
}
