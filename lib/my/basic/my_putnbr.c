/*
** EPITECH PROJECT, 2026
** my_put_nbr
** File description:
** Displays the number given as a parameter.
*/

#include "library.h"
#include <limits.h>

static void calcul(int nb, int diviseur)
{
    int temp;

    while (diviseur > 0) {
        temp = nb / diviseur;
        my_putchar(temp + '0');
        nb = nb % diviseur;
        diviseur /= 10;
    }
}

int my_putnbr(int nb)
{
    int diviseur = 0;

    diviseur = 1;
    if (nb == INT_MIN) {
        my_putchar('-');
        my_putchar('2');
        nb = 147483648;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while (diviseur <= nb / 10) {
        diviseur *= 10;
    }
    calcul(nb, diviseur);
    return (0);
}
