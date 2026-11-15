/*
** EPITECH PROJECT, 2026
** my_power
** File description:
** Return a to the power of b.
*/

#include "library.h"

double my_power(int a, int b)
{
    double result = a;

    if (b == 0)
        return 1.0;
    for (int i = 1; i < ABS(b); i++) {
        result *= a;
    }
    if (b < 0)
        return 1.0 / result;
    return result;
}
