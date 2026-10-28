/*
** EPITECH PROJECT, 2026
** my_print_g
** File description:
** Shortest representation between %f and %e.
*/

#include "library.h"

static int get_exponent(double nb)
{
    int exp = 0;

    if (nb == 0.0)
        return 0;
    while (nb >= 10.0) {
        nb /= 10.0;
        exp++;
    }
    while (nb < 1.0) {
        nb *= 10.0;
        exp--;
    }
    return exp;
}

static int trim_zeros(double nb, int prec, int hashtag)
{
    double rounded = nb + 0.5 * my_power(10, -prec);
    long dec = 0;

    if (hashtag || prec <= 0)
        return (prec < 0) ? 0 : prec;
    dec = (long)((rounded - (long)rounded) * my_power(10, prec));
    while (prec > 0 && dec % 10 == 0) {
        dec /= 10;
        prec--;
    }
    return prec;
}

static int print_dec_loop(double nb, int prec, int hashtag)
{
    int count = my_putnbr((long)nb);

    if (prec > 0 || hashtag)
        count += my_putchar('.');
    nb -= (long)nb;
    for (int i = 0; i < prec; i++) {
        nb *= 10.0;
        count += my_putchar((int)nb + '0');
        nb -= (int)nb;
    }
    return count;
}

static int print_g_sci(format_t *format, double nb, int exp)
{
    int count = 0;
    double mant = nb / my_power(10, exp);
    int prec = trim_zeros(mant, format->precision - 1, format->hashtag);

    mant += 0.5 * my_power(10, -(format->precision - 1));
    count += print_dec_loop(mant, prec, format->hashtag);
    count += my_putchar((format->conversion == 'G') ? 'E' : 'e');
    count += my_putchar((exp < 0) ? '-' : '+');
    if (ABS(exp) < 10)
        count += my_putchar('0');
    return count + my_putnbr(ABS(exp));
}

// Display a float number with automatic precision for my_printf
int my_print_g(format_t *format, va_list args)
{
    double nb = va_arg(args, double);
    int count = 0;
    int exp = 0;

    if (format->precision < 0)
        format->precision = 6;
    if (format->precision == 0)
        format->precision = 1;
    if (nb < 0) {
        count += my_putchar('-');
        nb = -nb;
    }
    exp = get_exponent(nb);
    if (exp < -4 || exp >= format->precision)
        return count + print_g_sci(format, nb, exp);
    format->precision = trim_zeros(nb, format->precision - 1 - exp,
        format->hashtag);
    nb += 0.5 * my_power(10, -(format->precision));
    return count + print_dec_loop(nb, format->precision, format->hashtag);
}
