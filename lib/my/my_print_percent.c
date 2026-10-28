/*
** EPITECH PROJECT, 2026
** my_print_percent
** File description:
** Displays a percentage sign.
*/

#include "library.h"

// Display a `%` with my_printf
int my_print_percent([[maybe_unused]] format_t *format,
    [[maybe_unused]] va_list args)
{
    return my_putchar('%');
}
