/*
** EPITECH PROJECT, 2026
** my_decimal_to_hex
** File description:
** Converts base 10 value in base 16.
*/

#include "library.h"

static int print_hex_rec(unsigned int nb, char *base)
{
    int count = 0;

    if (nb >= 16) {
        count += print_hex_rec(nb / 16, base);
    }
    count += my_putchar(base[nb % 16]);
    return count;
}

// Display a number in hexadecimal format with printf
int my_print_hex(format_t *format, va_list args)
{
    unsigned int nb = va_arg(args, unsigned int);
    char *base = "0123456789abcdef";
    int count = 0;

    if (format->conversion == 'X')
        base = "0123456789ABCDEF";
    if (format->hashtag)
        count += my_putstr((format->conversion == 'X') ? "0X" : "0x");
    count += print_hex_rec(nb, base);
    return count;
}
