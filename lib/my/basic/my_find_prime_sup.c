/*
** EPITECH PROJECT, 2026
** my_ﬁind_prime_sup
** File description:
** A function that returns the smallest prime number that is greater than,
** or equal to, the number given.
*/

#include <limits.h>
#include "library.h"

int my_find_prime_sup(int nb)
{
    if (nb < 2)
        nb = 2;
    for (; !my_is_prime(nb); nb++) {
        if (nb >= INT_MAX)
            return false;
    }
    return nb;
}
