/*
** EPITECH PROJECT, 2026
** my_strncmp
** File description:
** Reproduce the behavior of the strncmp function.
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (i = 0; s1[i] == s2[i] && s2[i] && i < n && s1[i]; i++);
    if (i == n)
        return (0);
    return s1[i] - s2[i];
}
