/*
** EPITECH PROJECT, 2019
** Pushswap
** File description:
** Header file for libmy.a
*/

#ifndef MY_H_
    #define MY_H_

    void my_putchar(char);
    void my_putstr(char const *);
    void my_puterr(char const *);
    void my_free_str_array(char **arr);
    void my_swap_int(int *nb1, int *nb2);

    int my_strtol(char *str, char **endptr);
    int my_strcmp(char const *s1, char const *s2);
    int my_atoi(char const *str);
    unsigned int my_count_char(char const *str, char const to_count);
    unsigned int my_count_until_sep(char const *str, char const sep);
    unsigned int my_strlen(char const *str);

    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    char *my_strdupcat(char const *s1, char const *s2);

    char **my_str_to_word_array(char *str, char const sep);
#endif