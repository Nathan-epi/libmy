/*
** EPITECH PROJECT, 2026
** my_put_unsigned_nbr
** File description:
** Displays the unsigned number given as a parameter.
*/

#include "library.h"

// Display positive number
int my_put_unsigned_nbr(unsigned int nb)
{
    long l_nb = nb;
    long divisor = 1;
    int count = 0;

    if (l_nb < 0) {
        count += my_putchar('-');
        l_nb = -l_nb;
    }
    while ((l_nb / divisor) >= 10)
        divisor *= 10;
    while (divisor > 0) {
        count += my_putchar((l_nb / divisor) % 10 + '0');
        divisor /= 10;
    }
    return count;
}
