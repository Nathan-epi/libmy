/*
** EPITECH PROJECT, 2026
** my_print_error
** File description:
** Display an error message in the terminal.
*/

#include "library.h"
#include <stddef.h>
#include <unistd.h>

void my_put_error(char *message)
{
    const char *UN_ERROR = "[ERROR] An unknown error occurred\n";
    const char *HEAD_ERROR = "[ERROR] ";
    int i = 0;

    if (message == NULL || message[0] == '\0') {
        write(2, UN_ERROR, my_strlen(UN_ERROR));
        return;
    }
    write(2, HEAD_ERROR, my_strlen(HEAD_ERROR));
    write(2, message, my_strlen(message));
    write(2, "\n", 1);
}
