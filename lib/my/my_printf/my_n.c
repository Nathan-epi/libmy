/*
** EPITECH PROJECT, 2026
** my_print_n
** File description:
** Writes the number of characters printed so far into an int * pointer.
*/

#include "library.h"
#include <stddef.h>
#include <stdint.h>

void check_cs(format_t *format, va_list args)
{
    char *char_ptr = va_arg(args, char *);
    short *s_ptr = va_arg(args, short *);

    switch (*format->length) {
        case 'h':
            if (format->length[1] == 'h') {
                *char_ptr = format->count;
                break;
            }
            *s_ptr = format->count;
            break;
    }
}

void check_lld(format_t *format, va_list args)
{
    long *l_ptr = va_arg(args, long *);
    long long *ll_ptr = va_arg(args, long long *);
    long double *ld_ptr = va_arg(args, long double *);

    switch (*format->length) {
        case 'l':
            if (format->length[1] == 'l'){
                *ll_ptr = format->count;
                break;
            }
            *l_ptr = format->count;
            break;
        case 'L':
            *ld_ptr = format->count;
            break;
    }
}

void check_sip(format_t *format, va_list args)
{
    size_t *z_ptr = va_arg(args, size_t *);
    intmax_t *j_ptr = va_arg(args, intmax_t *);
    ptrdiff_t *t_ptr = va_arg(args, ptrdiff_t *);

    switch (*format->length) {
        case 'z':
            *z_ptr = format->count;
            break;
        case 'j':
            *j_ptr = format->count;
            break;
        case 't':
            *t_ptr = format->count;
            break;
    }
}

// Return the number of character printed with my_printf
int my_n(format_t *format, va_list args)
{
    int *ptr = va_arg(args, int *);

    if (format->length == NULL || format->length[0] == '\0') {
        *ptr = format->count;
        return false;
    }
    check_cs(format, args);
    check_lld(format, args);
    check_sip(format, args);
    return false;
}
