/*
** EPITECH PROJECT, 2026
** my_print_scientific
** File description:
** Display the number in scientific notation.
*/

#include "library.h"

static int normalize_float(format_t *format, double *nb)
{
    int exp = 0;

    if (*nb != 0.0) {
        for (exp = 0; *nb >= 10.0; exp++)
            *nb /= 10.0;
        for (; *nb < 1.0; exp--)
            *nb *= 10.0;
    }
    *nb += 0.5 * my_power(10, -(format->precision));
    if (*nb >= 10.0) {
        *nb /= 10.0;
        exp++;
    }
    return exp;
}

static int print_exponent(int exp, char conv)
{
    int count = 0;

    count += my_putchar((conv == 'E') ? 'E' : 'e');
    count += my_putchar((exp < 0) ? '-' : '+');
    if (ABS(exp) < 10)
        count += my_putchar('0');
    count += my_putnbr(ABS(exp));
    return count;
}

static int print_mantissa(format_t *format, double nb)
{
    int i = 0;
    int count = 0;
    int int_part = (int)nb;
    double dec_part = nb - (double)int_part;

    count += my_putnbr(int_part);
    if (format->precision > 0 || format->hashtag)
        count += my_putchar('.');
    for (i = 0; i < format->precision; i++) {
        dec_part *= 10.0;
        count += my_putchar((int)dec_part + '0');
        dec_part -= (int)dec_part;
    }
    return count;
}

// Display a number in scientific notation with my_printf
int my_print_scientific(format_t *format, va_list args)
{
    double nb = va_arg(args, double);
    int count = 0;
    int exp = 0;

    if (format->precision < 0)
        format->precision = 6;
    if (nb < 0) {
        count += my_putchar('-');
        nb = -nb;
    }
    exp = normalize_float(format, &nb);
    count += print_mantissa(format, nb);
    count += print_exponent(exp, format->conversion);
    return count;
}
