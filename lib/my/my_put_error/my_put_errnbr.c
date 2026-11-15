/*
** EPITECH PROJECT, 2026
** my_put_errnbr
** File description:
** Print a number
*/

#include "library.h"
#include <limits.h>

static void calcul(int nb, int diviseur)
{
    int temp;

    while (diviseur > 0) {
        temp = nb / diviseur;
        my_put_errchar(temp + '0');
        nb = nb % diviseur;
        diviseur /= 10;
    }
}

// Print a number in stderr
void my_put_errnbr(int nb)
{
    int diviseur = 0;

    diviseur = 1;
    if (nb == INT_MIN) {
        my_put_errchar('-');
        my_put_errchar('2');
        nb = 147483648;
    }
    if (nb < 0) {
        my_put_errchar('-');
        nb = -nb;
    }
    while (diviseur <= nb / 10) {
        diviseur *= 10;
    }
    calcul(nb, diviseur);
}
