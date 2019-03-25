/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** Header for libmy.a
*/

#ifndef MY_H_
#define MY_H_

#include <stddef.h>

char *my_itoa(int nb);
int my_intlen(int nb);
char *my_revstr(char *str);
int my_atoi(char const *str);
void my_free_fields(char **array);
void *free_em(size_t var_nb, ...);
char **my_realloc_array(char **array);
int my_printf(const char *format, ...);
int my_str_isnum(char const *str, int neg);
int my_char_isin(char const c, char const *src);
int my_str_ends_with(const char *str, const char *end);
char **my_remove_ptr_fromarray(char **array, char *ptr);
char *my_str_addchar(char const *str, char const c, int index);

#endif /* MY_H_ */
