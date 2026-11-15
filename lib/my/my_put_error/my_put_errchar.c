/*
** EPITECH PROJECT, 2026
** my_put_errchar
** File description:
** Print a character
*/

#include "library.h"
#include <unistd.h>

// Print a character in stderr
void my_put_errchar(const char c)
{
    write(2, &c, 1);
}
