/*
** EPITECH PROJECT, 2026
** my_strlowcase
** File description:
** A function that puts every letter of every word in it in lowercase.
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return (str);
}
