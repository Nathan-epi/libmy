/*
** EPITECH PROJECT, 2026
** my_compute_square_root
** File description:
** A function that returns the square root.
*/

#include "library.h"

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb < 0)
        return false;
    for (i = 1; i <= nb / i; i++) {
        if (i * i == nb)
            return i;
    }
    return false;
}
