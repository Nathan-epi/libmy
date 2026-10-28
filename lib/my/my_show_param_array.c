/*
** EPITECH PROJECT, 2026
** my_show_params_array
** File description:
** A function that displays the content of an array created with
** the previous function.
*/

#include "library.h"

int my_show_param_array(struct info_param const *par)
{
    int i;
    int j;

    i = 0;
    while (par[i].str != 0) {
        my_putstr(par[i].str);
        my_putchar('\n');
        my_putnbr(par[i].length);
        my_putchar('\n');
        j = 0;
        while (par[i].word_array[j] != 0) {
            my_putstr(par[i].word_array[j]);
            my_putchar('\n');
            j++;
        }
        i++;
    }
    return 0;
}
