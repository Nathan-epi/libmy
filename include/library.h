/*
** EPITECH PROJECT, 2026
** Library
** File description:
** Project library
*/

#include <stdarg.h>

#ifndef LIBRARY_H
    #define LIBRARY_H
    #define ABS(value) ((value < 0) ? (-value) : (value))

// Static library function
struct info_param
{
    int length;
    char *str;
    char *copy;
    char **word_array;
};
int my_putchar(char c);
int my_isneg(int n);
int my_putnbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *array, int size);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size); //TODO: Implement logic
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int my_show_word_array(char *const *tab);
char **my_str_to_word_array(char const *str);
struct info_param *my_params_to_array(int ac, char **av);
int my_show_param_array(struct info_param const *par);
void my_put_error(char *message);
int my_strchr(char src, char *search);

// My_printf function
typedef struct s_format
{
    int plus;
    int zero;
    int minus;
    int space;
    int hashtag;
    int width;
    int precision;
    int count;
    char conversion;
    char *length;
} format_t;
int my_printf(const char *format, ...);
int my_print_str(format_t *format, va_list args);
int my_print_char(format_t *format, va_list args);
int my_print_nbr(format_t *format, va_list args);
int my_print_unsigned_nbr(format_t *format, va_list args);
int my_print_hex(format_t *format, va_list args);
int my_print_hex_address(format_t *format, va_list args);
int my_print_percent(format_t *format, va_list args);
int my_print_octal(format_t *format, va_list args);
int my_n(format_t *format, va_list args);
int my_print_binary(format_t *format, va_list args);
int my_print_float(format_t *format, va_list args);
int my_print_scientific(format_t *format, va_list args);
int my_print_g(format_t *format, va_list args);
int my_print_a(format_t *format, va_list args);
double my_power(int a, int b);
int my_put_unsigned_nbr(unsigned int nb);
int my_intlen(unsigned int nb);
typedef int (*conversion_t)(format_t *, va_list);
typedef struct s_conversion_map
{
    char conversion;
    conversion_t function;
} conversion_map_t;
static const conversion_map_t conversions[] = {
    {'s', my_print_str},
    {'c', my_print_char},
    {'i', my_print_nbr},
    {'d', my_print_nbr},
    {'u', my_print_unsigned_nbr},
    {'x', my_print_hex},
    {'X', my_print_hex},
    {'p', my_print_hex_address},
    {'%', my_print_percent},
    {'o', my_print_octal},
    {'n', my_n},
    {'b', my_print_binary},
    {'f', my_print_float},
    {'F', my_print_float},
    {'e', my_print_scientific},
    {'E', my_print_scientific},
    {'g', my_print_g},
    {'G', my_print_g},
    {'a', my_print_a},
    {'A', my_print_a}
};

#endif
