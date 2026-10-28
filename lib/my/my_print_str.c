/*
** EPITECH PROJECT, 2026
** my_print_str
** File description:
** Displays a string.
*/

#include "library.h"

static int print_padding(int pad_len)
{
    int count = 0;

    for (int i = 0; i < pad_len; i++) {
        count += my_putchar(' ');
    }
    return count;
}

// Display a string with printf
int my_print_str(format_t *format, va_list args)
{
    char *str = va_arg(args, char *);
    int len = 0;
    int count = 0;

    len = my_strlen(str);
    if (format->precision >= 0 && format->precision < len)
        len = format->precision;
    if (!format->minus)
        count += print_padding(format->width - len);
    for (int i = 0; i < len; i++) {
        count += my_putchar(str[i]);
    }
    if (format->minus)
        count += print_padding(format->width - len);
    return count;
}
