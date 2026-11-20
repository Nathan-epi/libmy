/*
** EPITECH PROJECT, 2026
** my_str_to_word_array
** File description:
** A function that splits a string into words.
*/

#include "library.h"
#include <stdlib.h>

static int is_alphanumeric(char c)
{
    if ((c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9'))
        return true;
    return false;
}

static int count_words(char const *str)
{
    int i = 0;
    int count = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (is_alphanumeric(str[i]) &&
            (i == 0 || !is_alphanumeric(str[i - 1])))
            count++;
    }
    return count;
}

static int word_length(char const *str, int start)
{
    int length = 0;

    for (length = 0; str[start + length] != '\0' &&
        is_alphanumeric(str[start + length]); length++);
    return length;
}

static char *copy_word(char const *str, int start)
{
    int i = 0;
    int length = word_length(str, start);
    char *word;

    word = malloc(sizeof(char) * (length + 1));
    if (word == NULL) {
        my_put_error("An allocation error occured. strtowo.memory2.error");
        return NULL;
    }
    for (i = 0; i < length; i++)
        word[i] = str[start + i];
    word[i] = '\0';
    return word;
}

// A function that splits a string into words.
char **my_str_to_word_array(char const *str)
{
    int i = 0;
    int word = 0;
    int words = count_words(str);
    char **array;

    array = malloc(sizeof(char *) * (words + 1));
    if (array == NULL) {
        my_put_error("An allocation error occured. strtowo.memory.error");
        return NULL;
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (is_alphanumeric(str[i]) &&
            (i == 0 || !is_alphanumeric(str[i - 1]))) {
            array[word] = copy_word(str, i);
            word++;
        }
    }
    array[word] = NULL;
    return array;
}
