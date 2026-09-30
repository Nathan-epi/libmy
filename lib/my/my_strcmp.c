/*
** EPITECH PROJECT, 2026
** my_strcmp
** File description:
** Reproduce the behavior of the strcmp function.
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    return s1[i] - s2[i];
}
