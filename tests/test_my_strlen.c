/*
** EPITECH PROJECT, 2026
** test_my_strlen
** File description:
** Test the my_strlen function
*/

#include "library.h"
#include <criterion/criterion.h>

Test(my_strlen, empty_string)
{
    cr_assert_eq(my_strlen(""), 0);
}

Test(my_strlen, simple_string)
{
    cr_assert_eq(my_strlen("Hello"), 5);
}

Test(my_strlen, back_charaters)
{
    cr_assert_eq(my_strlen("Hello\n"), 6);
}
