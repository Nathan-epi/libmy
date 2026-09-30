/*
** EPITECH PROJECT, 2026
** my_compute_power_rec
** File description:
** Recursive function that returns the ﬁrst argument raised to the power p.
*/

#include <limits.h>

static int check_overflow(int result, int nb)
{
    if (nb == 0)
        return 1;
    if (nb == 1 || nb == -1)
        return !(nb == -1 && result == INT_MIN);
    if (result > 0 && nb > 0 && result > INT_MAX / nb)
        return 0;
    if (result < 0 && nb < 0 && result < INT_MAX / nb)
        return 0;
    if (result > 0 && nb < 0 && result > INT_MIN / nb)
        return 0;
    if (result < 0 && nb > 0 && result < INT_MIN / nb)
        return 0;
    return 1;
}

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p < 0)
        return 0;
    if (p == 0)
        return 1;
    result = my_compute_power_rec(nb, p - 1);
    if (result == 0 && nb != 0)
        return 0;
    if (!check_overflow(result, nb))
        return 0;
    return nb * result;
}
