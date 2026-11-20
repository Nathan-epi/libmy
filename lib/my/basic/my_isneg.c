/*
** EPITECH PROJECT, 2026
** my_isneg
** File description:
** Display N if the variable is negative and P if is positive or null
*/

#include "library.h"

int my_isneg(int n)
{
    if (n >= 0)
        my_putstr("P\n");
    else
        my_putstr("N\n");
    return false;
}
