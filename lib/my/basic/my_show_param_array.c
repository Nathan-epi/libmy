/*
** EPITECH PROJECT, 2026
** my_show_params_array
** File description:
** A function that displays the content of an array created with
** the previous function.
*/

#include "library.h"

// Display the parameters stored in info_param
int my_show_param_array(struct info_param const *par)
{
    int i = 0;
    int j = 0;

    for (i = 0; par[i].str != 0; i++) {
        my_putstr(par[i].str);
        my_putchar('\n');
        my_putnbr(par[i].length);
        my_putchar('\n');
        for (j = 0; par[i].word_array[j] != 0; j++) {
            my_putstr(par[i].word_array[j]);
            my_putchar('\n');
        }
    }
    return false;
}
