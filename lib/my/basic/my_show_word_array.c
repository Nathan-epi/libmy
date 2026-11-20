/*
** EPITECH PROJECT, 2026
** concat_params
** File description:
** A function that turns the command-line given arguments into a single string.
*/

#include "library.h"
#include <stdlib.h>

int my_show_word_array(char *const *tab)
{
    int i = 0;

    for (i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return false;
}
