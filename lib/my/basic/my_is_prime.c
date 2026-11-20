/*
** EPITECH PROJECT, 2026
** my_is_prime
** File description:
** A function that returns 1 if the number is prime and 0 if not.
*/

#include "library.h"

// Detect if the number given is a prime number of not, return `1` or `O`
int my_is_prime(int nb)
{
    int i = 0;

    if (nb <= 0 || nb == 1)
        return false;
    for (i = 2; i <= nb / i; i++) {
        if (nb % i == 0)
            return false;
    }
    return true;
}
