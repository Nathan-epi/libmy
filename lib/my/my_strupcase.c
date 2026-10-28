/*
** EPITECH PROJECT, 2026
** my_strupcase
** File description:
** A function that puts every letter of every word in it in uppercase.
*/

// Put every letter in uppercase
char *my_strupcase(char *str)
{
    int i = 0;

    for (i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return (str);
}
