/*
** EPITECH PROJECT, 2026
** my_print_a
** File description:
** Converts a float in hexadecimal scientific notation.
*/

#include "library.h"

static int handle_flags(format_t *format, double *nb)
{
    int count = 0;

    if (*nb < 0) {
        count += my_putchar('-');
        *nb = -(*nb);
    }
    if (format->plus) {
        count += (nb > 0) ? my_putchar('+') : 0;
    }
    if (format->space) {
        count += my_putchar(' ');
    }
    count += my_putstr((format->conversion == 'A') ? "0X" : "0x");
    return count;
}

static int calc_hex_float(double *nb)
{
    int exp = 0;

    if (*nb == 0.0)
        return 0;
    while (*nb >= 2.0) {
        *nb /= 2.0;
        exp++;
    }
    while (*nb < 1.0) {
        *nb *= 2.0;
        exp--;
    }
    return exp;
}

static int print_hex_decimals(format_t *format, double dec)
{
    int count = 0;
    char *base = (format->conversion == 'A') ?
        "0123456789ABCDEF" : "0123456789abcdef";

    if ((dec > 0.0 && format->precision != 0) ||
        format->precision > 0 || format->hashtag)
        count += my_putchar('.');
    for (int i = 0; (format->precision < 0 && dec > 0.0 && i < 13) ||
        i < format->precision; i++) {
        dec *= 16.0;
        count += my_putchar(base[(int)dec]);
        dec -= (int)dec;
    }
    return count;
}

// Display a float number in hexadecimal number with my_printf
int my_print_a(format_t *format, va_list args)
{
    double nb = va_arg(args, double);
    int count = handle_flags(format, &nb);
    int exp = calc_hex_float(&nb);
    int int_part = 0;

    if (format->precision >= 0)
        nb += 0.5 * my_power(16, -(format->precision));
    if (nb >= 2.0) {
        nb /= 2.0;
        exp++;
    }
    int_part = (int)nb;
    count += my_putchar(int_part + '0');
    count += print_hex_decimals(format, nb - int_part);
    count += my_putchar((format->conversion == 'A') ? 'P' : 'p');
    count += my_putchar((exp < 0) ? '-' : '+');
    return count + my_putnbr(ABS(exp));
}
