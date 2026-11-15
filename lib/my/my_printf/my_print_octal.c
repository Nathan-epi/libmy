/*
** EPITECH PROJECT, 2026
** my_print_octal
** File description:
** Converts base 10 value in base 8.
*/

#include "library.h"

static int print_octal_rec(unsigned int nb, char *base)
{
    int count = 0;

    if (nb >= 8) {
        count += print_octal_rec(nb / 8, base);
    }
    count += my_putchar(base[nb % 8]);
    return count;
}

// Display a number in octal format with my_printf
int my_print_octal([[maybe_unused]] format_t *format, va_list args)
{
    unsigned int nb = va_arg(args, unsigned int);
    char *base = "01234567";

    return print_octal_rec(nb, base);
}
