/*
** EPITECH PROJECT, 2026
** my_revstr
** File description:
** A function that reverses a string.
*/

#include "library.h"

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    int i = 0;
    int j = 0;
    char new_str[len + 1];

    for (i = len - 1; i >= 0; i--) {
        new_str[j] = str[i];
        j++;
    }
    new_str[j] = '\0';
    for (i = 0; new_str[i] != '\0'; i++) {
        str[i] = new_str[i];
    }
    return str;
}
