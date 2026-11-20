/*
** EPITECH PROJECT, 2026
** my_hex_adress.c
** File description:
** Converts a pointer adress in hexadecimal.
*/

#include "library.h"
#include <stddef.h>

static int get_hex_len(unsigned long nb)
{
    int len = 1;

    while (nb >= 16) {
        nb /= 16;
        len++;
    }
    return len;
}

static int print_hex_rec(unsigned long address, char *base)
{
    int count = 0;

    if (address >= 16) {
        count += print_hex_rec(address / 16, base);
    }
    count += my_putchar(base[address % 16]);
    return count;
}

static int print_spaces(int nb_spaces)
{
    int i = 0;
    int count = 0;

    for (i = 0; i < nb_spaces; i++)
        count += my_putchar(' ');
    return count;
}

// Display a memory address is hexadecimal format with printf
int my_print_hex_address(format_t *format, va_list args)
{
    void *ptr = va_arg(args, void *);
    int count = 0;
    int len = (ptr == NULL) ? 5 : 2 + get_hex_len((unsigned long)ptr);
    int spaces = format->width - len;

    if (!format->minus)
        count += print_spaces(spaces);
    if (ptr == NULL) {
        count += my_putstr("(nil)");
    } else {
        count += my_putstr("0x");
        count += print_hex_rec((unsigned long)ptr, "0123456789abcdef");
    }
    if (format->minus)
        count += print_spaces(spaces);
    return count;
}
