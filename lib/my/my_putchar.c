/*
** EPITECH PROJECT, 2026
** My_putchar
** File description:
** Write char element int the terminal
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
