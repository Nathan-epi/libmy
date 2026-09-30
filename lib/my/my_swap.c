/*
** EPITECH PROJECT, 2026
** my_swap
** File description:
** Swaps the content of two integers
*/

void my_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}
