/*
** EPITECH PROJECT, 2026
** my_intlen
** File description:
** Returns the length of an int.
*/

// Return the lenght of an int
int my_intlen(unsigned int nb)
{
    int len = 0;

    for (len = 1; nb >= 10; len++)
        nb /= 10;
    return len;
}
