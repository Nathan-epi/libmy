/*
** EPITECH PROJECT, 2026
** my_print_nbr
** File description:
** Displays a number.
*/

#include "library.h"

static void get_space(format_t *format, int *nb_space, int *nb_print)
{
    if (format->width > *nb_print) {
        *nb_space = format->width - *nb_print;
        *nb_print += *nb_space;
    }
}

static void get_zero(format_t *format, int *nb_zero, int *nb_print)
{
    if (format->precision > *nb_print) {
        *nb_zero = format->precision - *nb_print;
        *nb_print += *nb_zero;
    }
}

static void print2(format_t *format, int nb_space, int nb_zero, int *count)
{
    int i = 0;

    if (format->minus == 0) {
        for (i = 0; i < nb_space; i++)
            *count += my_putchar(' ');
    }
    for (i = 0; i < nb_zero; i++)
        *count += my_putchar('0');
}

static void print(format_t *format, int *count, int nb_space, int nb)
{
    int i = 0;

    *count += my_putnbr(nb);
    if (format->minus) {
        for (i = 0; i < nb_space; i++)
            *count += my_putchar(' ');
    }
}

// Display a number with printf
int my_print_nbr(format_t *format, va_list args)
{
    int nb = va_arg(args, int);
    int nb_print = my_intlen(nb);
    int nb_space = 0;
    int nb_zero = 0;
    int count = 0;

    if (format->space) {
        count += my_putchar(' ');
    }
    if (format->plus)
        count += (nb >= 0) ? my_putchar('+') : 0;
    get_zero(format, &nb_zero, &nb_print);
    get_space(format, &nb_space, &nb_print);
    print2(format, nb_space, nb_zero, &count);
    print(format, &count, nb_space, nb);
    return count;
}
