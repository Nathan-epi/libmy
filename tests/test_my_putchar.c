/*
** EPITECH PROJECT, 2026
** test_my_putchar
** File description:
** Test the my_putchar function
*/

#include "library.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_putchar, empty_char)
{
    cr_redirect_stdout();
    my_putchar(' ');
    cr_assert_stdout_eq_str(" ");
}

Test(my_putchar, back_charaters)
{
    cr_redirect_stdout();
    my_putchar('\n');
    cr_assert_stdout_eq_str("\n");
}
