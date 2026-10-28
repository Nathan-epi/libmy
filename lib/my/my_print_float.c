/*
** EPITECH PROJECT, 2026
** my_print_float
** File description:
** Displays a decimal floating point number.
*/

#include "library.h"

static char get_sign_char(format_t *format, double *nb)
{
    if (*nb < 0.0) {
        *nb = -(*nb);
        return '-';
    }
    if (format->plus)
        return '+';
    if (format->space)
        return ' ';
    return '\0';
}

static int print_spaces(int len, char c)
{
    int count = 0;

    for (int i = 0; i < len; i++) {
        count += my_putchar(c);
    }
    return count;
}

static int print_decimals(format_t *format, double dec_part)
{
    int count = 0;

    if (format->precision > 0 || format->hashtag)
        count += my_putchar('.');
    for (int i = 0; i < format->precision; i++) {
        dec_part *= 10.0;
        count += my_putchar((int)dec_part + '0');
        dec_part -= (int)dec_part;
    }
    return count;
}

// Display a float number with my_printf
int my_print_float(format_t *format, va_list args)
{
    double nb = va_arg(args, double);
    char sign = get_sign_char(format, &nb);
    int count = 0;
    int spaces = 0;

    if (format->precision < 0)
        format->precision = 6;
    nb += 0.5 * my_power(10, -(format->precision));
    spaces = format->width - (my_intlen((unsigned int)nb) + format->precision +
        (format->precision > 0 || format->hashtag ? 1 : 0) + (sign != '\0'));
    if (!format->minus && !format->zero)
        count += print_spaces(spaces, ' ');
    if (sign != '\0')
        count += my_putchar(sign);
    if (!format->minus && format->zero)
        count += print_spaces(spaces, '0');
    count += my_putnbr((int)nb);
    count += print_decimals(format, nb - (long)nb);
    return count + (format->minus ? print_spaces(spaces, ' ') : 0);
}
