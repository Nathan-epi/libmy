/*
** EPITECH PROJECT, 2026
** my_printf
** File description:
** The essential file of the project
*/

#include "library.h"
#include <stddef.h>

/* Handle the call to the needed function */
static int call(format_t *specifier, int *count, va_list args)
{
    int i = 0;
    int len = sizeof(conversions) / sizeof(conversions[0]);

    specifier->count = *count;
    for (i = 0; i < len; i++) {
        if (conversions[i].conversion == specifier->conversion) {
            *count += conversions[i].function(specifier, args);
            return 0;
        }
    }
    my_put_error("Unable to find the correct function");
    return -1;
}

/* Detect double length modifiers */
static void get_double_lenght(const char *format, format_t *specifier, int *i)
{
    if (format[*i] == 'h') {
        specifier->length = "h\0";
        if (format[*i + 1] == 'h') {
            specifier->length = "hh\0";
            (*i)++;
        }
    }
    if (format[*i] == 'l') {
        specifier->length = "l\0";
        if (format[*i + 1] == 'l') {
            specifier->length = "ll\0";
            (*i)++;
        }
    }
}

/* Detect length modifiers */
static void get_length(const char *format, format_t *specifier, int *i)
{
    switch (format[*i]) {
        case 'L':
            specifier->length = "L\0";
            break;
        case 'z':
            specifier->length = "z\0";
            break;
        case 'j':
            specifier->length = "j\0";
            break;
        case 't':
            specifier->length = "t\0";
            break;
        case 'h':
        case 'l':
            get_double_lenght(format, specifier, i);
            break;
    }
}

/* Detect precision value */
static void get_prec(const char *format, format_t *spec, int *i, va_list args)
{
    if (format[*i] != '.')
        return;
    (*i)++;
    if (format[*i] == '*')
        spec->precision = va_arg(args, int);
    if (format[*i] >= '0' && format[*i] <= '9') {
        if (spec->precision == -1)
            spec->precision = 0;
        for (; format[*i] >= '0' && format[*i] <= '9'; (*i)++)
            spec->precision = spec->precision * 10 + (format[*i] - '0');
        (*i)--;
    }
}

/* Detect width value */
static void get_width(const char *format, format_t *spec, int *i, va_list args)
{
    if (format[*i] == '*')
        spec->width = va_arg(args, int);
    if (format[*i] >= '0' && format[*i] <= '9') {
        if (spec->width == -1)
            spec->width = 0;
        for (; format[*i] >= '0' && format[*i] <= '9'; (*i)++)
            spec->width = spec->width * 10 + (format[*i] - '0');
        (*i)--;
    }
}

/* Detect all present flags */
static void flags_handler(const char *format, format_t *specifier, int i)
{
    switch (format[i]) {
        case '+':
            specifier->plus = 1;
            break;
        case '-':
            specifier->minus = 1;
            break;
        case '0':
            specifier->zero = 1;
            break;
        case ' ':
            specifier->space = 1;
            break;
        case '#':
            specifier->hashtag = 1;
            break;
    }
}

/* The actual parser of the project */
static int parser(const char *format, format_t *specifier, int *i, va_list args)
{
    (*i)++;
    specifier->precision = -1;
    specifier->width = -1;
    for (; format[*i] != '\0'; (*i)++) {
        if (my_strchr(format[*i], "cspdiuoxXfFeEgGaAn%bS") == 1) {
            specifier->conversion = format[*i];
            return 0;
        }
        flags_handler(format, specifier, *i);
        get_width(format, specifier, i, args);
        get_prec(format, specifier, i, args);
        get_length(format, specifier, i);
    }
    my_put_error("Unable to find the end of the specifier.");
    return -1;
}

/* Custom implementation of printf */
int my_printf(const char *format, ...)
{
    int i = 0;
    int count = 0;
    va_list args;
    format_t specifier;

    va_start(args, format);
    for (i = 0; format[i] != '\0'; i++) {
        specifier = (format_t){0};
        if (format[i] != '%') {
            count += my_putchar(format[i]);
            continue;
        }
        if (format[i] == '%' && parser(format, &specifier, &i, args) == -1) {
            return -1;
        }
        if (call(&specifier, &count, args) == -1)
            return -1;
    }
    va_end(args);
    return count;
}
