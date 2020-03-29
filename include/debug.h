/*
** EPITECH PROJECT, 2020
** debug
** File description:
** tetris
*/

#include <stdbool.h>
#include <dirent.h>

#ifndef tetris_game
    #define tetris_game

    typedef struct debug_info {
        char drop;
        char key_turn;
        char pause;
        char quit;
        char level;
        char left_key;
        char right_key;
        bool next;
    }debug_t;

    debug_t *basic_input(void);
    int my_strncmp(char const *s1, char const *s2);
    bool debug_mod_disp_key(char **av);
    char drop_change(char **str);
    void my_putchar(char c);
    debug_t *change_input(char **str);
    char left_key(char **str);
    char right_key(char **str);
    int get_nb_files_in_dir(char const *pathname);
    bool debug_mod_disp_tetrimino_inf(char const *str);
    char *get_file_buffer(char const *filepath);
    bool debug_mod_disp_lvl_info(void);
    char *get_file_name(DIR *file);
    void my_putstr(char const *str);
    char *my_strcpy(char *dest, char const *src);
    char **my_str_to_word_tab(char *buff);
    char *my_strcpy_a(char *str);
    char *my_strdup_a(char * to_copy);
    int my_put_nbr(int nb);
    char *prompt_command(void);
    char * my_strcat(char *output, char const *input);
    int get_size(char *name);
    int get_color(char *name);
#endif