/*
** EPITECH PROJECT, 2026
** my_isneg
** File description:
** Display N if the variable is negative and P if is positive or null
*/

#include "library.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
        my_putchar('\n');
    } else {
        my_putchar('N');
        my_putchar('\n');
    }
    return (0);
}
