/*
** EPITECH PROJECT, 2026
** My_putchar
** File description:
** Write char element int the terminal
*/

#include <unistd.h>

// Display an unique character
int my_putchar(char c)
{
    return write(1, &c, 1);
}
