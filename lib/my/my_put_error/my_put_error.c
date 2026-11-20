/*
** EPITECH PROJECT, 2026
** my_print_error
** File description:
** Display an error message in the terminal.
*/

#include "library.h"
#include <stddef.h>

static void cases(const char format, va_list args)
{
    switch (format) {
        case 'd':
        case 'i':
            my_put_errnbr(va_arg(args, int));
            break;
        case 's':
            my_put_errstr(va_arg(args, char *));
            break;
        case 'c':
            my_put_errchar(va_arg(args, int));
            break;
        case '%':
            my_put_errchar('%');
            break;
        default:
            my_put_errstr("Unsupported argument detected !");
            break;
    }
}

// Display an error message
// Add `[ERROR]` at the beggining of the message and `\n` at the end
// Supported tags `%i`, `%d`, `%s`, `%c` and `%%`
// For empty message display a pre-configured standard error message
void my_put_error(const char *format, ...)
{
    va_list args;
    const char *UN_ERROR = "[ERROR] An unknown error occurred\n";
    const char *HEAD_ERROR = "[ERROR] ";

    va_start(args, format);
    if (format == NULL) {
        my_put_errstr(UN_ERROR);
        return;
    }
    my_put_errstr(HEAD_ERROR);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            cases(format[i + 1], args);
            i++;
            continue;
        }
        my_put_errchar(format[i]);
    }
    va_end(args);
    my_put_errchar('\n');
}
