/*
** EPITECH PROJECT, 2026
** test_my_strchr.c
** File description:
** test_my_strchr.c
*/

#include "library.h"
#include <criterion/criterion.h>

Test(my_strchr, in_string)
{
    cr_assert_eq(my_strchr('A', "ZgdjfhujA"), 1);
}

Test(my_strchr, not_in_string)
{
    cr_assert_eq(my_strchr('A', "gfurfjnjia"), 0);
}
