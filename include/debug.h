/*
** EPITECH PROJECT, 2020
** debug
** File description:
** tetris
*/

#ifndef tetris
    #define tetris

    typedef struct debug_info {
        char *drop;
        char *key_turn;
        char *pause;
        char *quit;
    }debug_t;

    debug_t *basic_input(void);
    int my_strncmp(char const *s1, char const *s2);

#endif