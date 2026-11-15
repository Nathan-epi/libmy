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

    if (src == NULL)
        return NULL;
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (str == NULL)
        return NULL;
    for (; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}
