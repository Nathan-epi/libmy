/*
** EPITECH PROJECT, 2026
** my_strlen
** File description:
** Counts and returns the number of characters found in the string.
*/

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}
