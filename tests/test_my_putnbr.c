/*
** EPITECH PROJECT, 2026
** test_my_putnbr.c
** File description:
** Test the my_putnbr function
*/

#include "library.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <limits.h>

Test(my_putnbr, normal_number)
{
    cr_redirect_stdout();
    my_putnbr(35);
    cr_assert_stdout_eq_str("35");
}

Test(my_putnbr, int_min)
{
    cr_redirect_stdout();
    my_putnbr(INT_MIN);
    cr_assert_stdout_eq_str("-2147483648");
}

Test(my_putnbr, negative_number)
{
    cr_redirect_stdout();
    my_putnbr(-1);
    cr_assert_stdout_eq_str("-1");
}
