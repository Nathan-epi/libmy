/*
** EPITECH PROJECT, 2026
** test_my_put_error
** File description:
** Test the my_put_error function
*/

#include "library.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(my_put_error, empty_message)
{
    cr_redirect_stderr();
    my_put_error("");
    cr_assert_stderr_eq_str("[ERROR] An unknown error occurred\n");
}

Test(my_put_error, empty_message_bis)
{
    cr_redirect_stderr();
    my_put_error(NULL);
    cr_assert_stderr_eq_str("[ERROR] An unknown error occurred\n");
}

Test(my_put_error, classic_message)
{
    cr_redirect_stderr();
    my_put_error("You give an unsupported argument !");
    cr_assert_stderr_eq_str("[ERROR] You give an unsupported argument !\n");
}
