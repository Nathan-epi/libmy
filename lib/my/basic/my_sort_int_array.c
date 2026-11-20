/*
** EPITECH PROJECT, 2026
** my_sort_int_array
** File description:
** Sorts an integer array in ascending order.
*/

#include "library.h"

static void sort_pass(int *array, int limit)
{
    int j = 0;
    int temp = 0;

    for (j = 0; j < limit; j++) {
        if (array[j] > array[j + 1]) {
            temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
        }
    }
}

// Sorts an integer array in ascending order
void my_sort_int_array(int *array, int size)
{
    int i = 0;

    if (size <= 0) {
        my_put_error("Invalid given size : %i", size);
        return;
    }
    for (i = 0; i < size - 1; i++)
        sort_pass(array, size - i - 1);
}
