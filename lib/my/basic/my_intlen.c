/*
** EPITECH PROJECT, 2026
** my_intlen
** File description:
** Returns the length of an int.
*/

// Return the lenght of an int
int my_intlen(unsigned int nb)
{
    int len = 1;

    while (nb >= 10) {
        nb /= 10;
        len++;
    }
    return len;
}
