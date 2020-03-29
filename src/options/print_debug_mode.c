/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** print_debug_mode
*/

#include <stdbool.h>
#include "tetris.h"
#include "my.h"
#include "debug.h"
#include <stdio.h>

bool debug_mod_disp_key(char **av)
{
    debug_t *info = change_input(av);
    my_putstr("*** DEBUG MODE ***\n");
    my_putstr("Key Left : ");
    my_putchar(info->left_key);
    my_putstr("\nKey Right : ");
    my_putchar(info->right_key);
    my_putstr("\nKey Turn : ");
    my_putchar(info->key_turn);
    my_putstr("\nKey Drop : ");
    my_putchar(info->drop);
    my_putstr("\nKey Quit : ");
    my_putchar(info->quit);
    my_putstr("\nKey Pause : ");
    my_putchar(info->pause);
    return true;
}

bool debug_mod_disp_lvl_info(void)
{
    my_putstr("\nNext : Yes\n");
    my_putstr("Level : 1\n");
    my_putstr("Size : 20*20\n");
    return true;
}

bool debug_mod_disp_tetrimino_inf(char const *filepath)
{
    int nb = get_nb_files_in_dir(filepath);
    char *str = NULL;
    char *name = NULL;

    my_putstr("Tetriminos : ");
    my_put_nbr(nb);
    str = get_file_name(opendir("./tetriminos"));
    name = my_strcat("./tetriminos/", str);

    for (int i = 0; i != nb; i++) {
        my_putstr("\nTetriminos : Name ");
        my_putstr(str);
        get_file_buffer(name);
        my_putstr(" : Size ");
        get_size(name);
        my_putstr(" : Color ");
        get_color(name);
    }
    my_putstr("\nPress any key to start Tetris\n");
    return true;
}