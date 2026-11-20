/*
** EPITECH PROJECT, 2026
** my_params_to_array
** File description:
** A function that stores the program's parameters into an array of structures
** and returns the address of the array's first cell.
*/

#include "library.h"
#include <stdlib.h>

// Store the program's parameters in a array of strutures
struct info_param *my_params_to_array(int ac, char **av)
{
    int i = 0;
    struct info_param *array;

    array = malloc(sizeof(struct info_param) * (ac + 1));
    if (array == NULL) {
        my_put_error("An error occured with memory allocation."
            " pararray.memory.error");
        return NULL;
    }
    for (i = 0; i < ac; i++) {
        array[i].length = my_strlen(av[i]);
        array[i].str = av[i];
        array[i].copy = my_strdup(av[i]);
        array[i].word_array = my_str_to_word_array(av[i]);
    }
    array[ac].str = 0;
    return array;
}
