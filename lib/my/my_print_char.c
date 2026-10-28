/*
** EPITECH PROJECT, 2026
** my_print_char
** File description:
** Displays a character.
*/

#include "library.h"

static int print_spaces(int nb_spaces)
{
    int count = 0;

    for (int i = 0; i < nb_spaces; i++) {
        count += my_putchar(' ');
    }
    return count;
}

// Display a unique character with printf
int my_print_char(format_t *format, va_list args)
{
    char c = (char)va_arg(args, int);
    int count = 0;
    int spaces = format->width - 1;

    if (!format->minus)
        count += print_spaces(spaces);
    count += my_putchar(c);
    if (format->minus)
        count += print_spaces(spaces);
    return count;
}
