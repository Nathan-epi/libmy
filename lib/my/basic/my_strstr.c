/*
** EPITECH PROJECT, 2026
** my_strstr
** File description:
** Reproduce the behavior of the strstr function.
*/

#include "library.h"
#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    if (to_find[0] == '\0') {
        return str;
    }
    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; to_find[j] != '\0' && str[i + j] == to_find[j]; j++);
        if (to_find[j] == '\0') {
            return &str[i];
        }
    }
    return NULL;
}
