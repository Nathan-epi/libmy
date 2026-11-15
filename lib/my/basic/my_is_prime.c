/*
** EPITECH PROJECT, 2026
** my_is_prime
** File description:
** A function that returns 1 if the number is prime and 0 if not.
*/

#include "library.h"

int my_is_prime(int nb)
{
    int i;

    if (nb <= 0 || nb == 1)
        return 0;
    i = 2;
    while (i <= nb / i) {
        if (nb % i == 0)
            return 0;
        i++;
    }
    return 1;
}
