/*
** EPITECH PROJECT, 2026
** my_showstr
** File description:
** A function that prints a string with it's non-printable characters
** and returns 0
*/

#include "library.h"
#include <ctype.h>

// Display a string with non-printable characters in hexadecimal format
int my_showstr(char const *str)
{
    int i = 0;
    unsigned char c;
    char const *hex = "0123456789abcdef";

    for (i = 0; str[i] != '\0'; i++) {
        c = (unsigned char)str[i];
        if (c < 32 || c >= 127) {
            my_putchar('\\');
            my_putchar(hex[c / 16]);
            my_putchar(hex[c % 16]);
        } else {
            my_putchar(str[i]);
        }
    }
    return 0;
}
