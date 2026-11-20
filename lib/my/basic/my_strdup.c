/*
** EPITECH PROJECT, 2026
** my_strdup
** File description:
** A function that allocates memory and copies the string given.
*/

#include "library.h"
#include <stdlib.h>

// Allocate memory and copies the given string
char *my_strdup(char const *src)
{
    int i = 0;
    char *str;

    if (src == NULL) {
        my_put_error("There is no string to copy. strdup.src.null");
        return NULL;
    }
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (str == NULL) {
        my_put_error("An allocation error occured. strdup.memory.error");
        return NULL;
    }
    for (i = 0; src[i] != '\0'; i++)
        str[i] = src[i];
    str[i] = '\0';
    return str;
}
