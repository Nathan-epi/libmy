/*
** EPITECH PROJECT, 2026
** my_putstr
** File description:
** Displays one-by-one, the characters of a string.
*/

#include "library.h"

// Display the character of a string
int my_putstr(char const *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return false;
}
