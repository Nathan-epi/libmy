/*
** EPITECH PROJECT, 2026
** my_sort_int_array
** File description:
** Sorts an integer array in ascending order.
*/

static void sort_pass(int *array, int limit)
{
    int j;
    int temp;

    for (j = 0; j < limit; j++) {
        if (array[j] > array[j + 1]) {
            temp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temp;
        }
    }
}

void my_sort_int_array(int *array, int size)
{
    int i;

    if (size <= 0) {
        return;
    }
    for (i = 0; i < size - 1; i++) {
        sort_pass(array, size - i - 1);
    }
}
