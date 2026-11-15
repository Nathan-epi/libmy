/*
** EPITECH PROJECT, 2026
** my_put_errstr
** File description:
** Print a string
*/

#include "library.h"

// Print a string in stderr
void my_put_errstr(const char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        my_put_errchar(str[i]);
    }
}
