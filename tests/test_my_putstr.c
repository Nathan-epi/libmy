/*
** EPITECH PROJECT, 2026
** test_my_putstr
** File description:
** Test the my_putstr function
*/

#include "library.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_putstr, empty_string)
{
    cr_redirect_stdout();
    my_putstr("");
    cr_assert_stdout_eq_str("");
}

Test(my_putstr, classic_string)
{
    cr_redirect_stdout();
    my_putstr("Hello world !");
    cr_assert_stdout_eq_str("Hello world !");
}

Test(my_putstr, backslash_string)
{
    cr_redirect_stdout();
    my_putstr("Hello world !\n");
    cr_assert_stdout_eq_str("Hello world !\n");
}
