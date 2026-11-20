/*
** EPITECH PROJECT, 2026
** my_print_binary
** File description:
** Converts base 10 value in base 2.
*/

#include "library.h"

static int print_binary_rec(unsigned int nb, char *base)
{
    int count = 0;

    if (nb >= 2)
        count += print_binary_rec(nb / 2, base);
    count += my_putchar(base[nb % 2]);
    return count;
}

// Display a number in binary format with my_printf
int my_print_binary([[maybe_unused]] format_t *format, va_list args)
{
    unsigned int nb = va_arg(args, unsigned int);
    char *base = "01";

    return print_binary_rec(nb, base);
}
