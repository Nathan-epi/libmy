/*
** EPITECH PROJECT, 2026
** my_getnbr
** File description:
** Returns a number, sent to the function as a string.
*/

#include "library.h"
#include <stddef.h>
#include <limits.h>

static int is_numbers(char c)
{
    return (c >= '0' && c <= '9');
}

static int signe(int is_neg, char sig)
{
    if (sig == '-') {
        is_neg += 1;
    }
    return is_neg;
}

static int check_overflow(long number, int is_neg)
{
    if (is_neg % 2 == 0 && number > INT_MAX)
        return true;
    if (is_neg % 2 != 0 && number > -(long)INT_MIN)
        return true;
    return false;
}

static int handle_number(char c, int *number, int is_neg)
{
    long temp = 0;

    if (!is_numbers(c))
        return false;
    temp = (long) *number * 10 + (c - '0');
    if (check_overflow(temp, is_neg))
        return 1;
    *number = (int)temp;
    return false;
}

// Receive a number in char* and return a int
int my_getnbr(char const *str)
{
    int is_neg = 0;
    int number = 0;
    int i = 0;

    if (str == NULL || str[0] == '\0')
        return false;
    for (i = 0; str[i] == '+' || str[i] == '-'; i++)
        is_neg = signe(is_neg, str[i]);
    while (is_numbers(str[i])) {
        if (handle_number(str[i], &number, is_neg))
            return false;
        i++;
    }
    if (is_neg % 2 != 0)
        number = -number;
    return number;
}
