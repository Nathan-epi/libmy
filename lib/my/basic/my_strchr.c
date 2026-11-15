/*
** EPITECH PROJECT, 2026
** my_strchr.c
** File description:
** my_strchr.c
*/

#include "library.h"

// Check if a char is in a char *
// return 0 if not present and 1 if present
int my_strchr(char src, char *search)
{
    int i = 0;

    for (i = 0; search[i] != '\0'; i++) {
        if (search[i] == src)
            return 1;
    }
    return 0;
}
