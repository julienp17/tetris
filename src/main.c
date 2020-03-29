/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Main file for tetris
*/

#include <stdlib.h>
#include <time.h>
#include "tetris.h"
#include "debug.h"

int debug_check(char **str)
{
    int i = 0;
    int j = 0;
    int check = 0;

    for (i = 0; str[i] != NULL; i++) {
        if (str[i][j] == '-') {
            check = 1;
            j++;
        }
        if (str[i][j] == 'D' && check == 1)
            check = 2;
        if (check == 2)
            return 1;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (print_help(ac, av))
        return (0);
    if (ac != 1 && debug_check(av) == 1) {
        debug_mod_disp_key(av);
        drop_change(av);
        debug_mod_disp_lvl_info();
        debug_mod_disp_tetrimino_inf("./tetriminos");
        prompt_command();
        tetris();
    } else
        tetris();
    srand(time(NULL));
    return (0);
}