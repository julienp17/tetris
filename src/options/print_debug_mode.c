/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** print_debug_mode
*/

#include "stdbool.h"
#include "tetris.h"
#include "my.h"

bool debug_mod_disp_key(int ac, char **av)
{
    my_putstr("*** DEBUG MODE ***\n");
    my_putstr("Key Left : ^EOD\n");
    my_putstr("Key Right : ^EOC\n");
    my_putstr("Key Turn : (space)\n");
    my_putstr("Key Drop : x\n");
    my_putstr("Key Quit : q\n");
    my_putstr("Key Pause : p\n");
}

bool debug_mod_disp_lvl_info(int ac, char **av)
{
    my_putstr("Next : Yes\n");
    my_putstr("Level : 1\n");
    my_putstr("Size : 20*20\n");
}

bool debug_mod_disp_tetrimino_inf(int ac, char **av)
{
    my_putstr("Tetriminos : 7");
    my_putstr("Tetriminos : Name 4 : Error");
    my_putstr("Tetriminos : Name 5 : Size 1*1 : Color 4 :\n");
    //tetrimino
    my_putstr("Tetriminos : Name 6 : Size 2*3 : Color 6 :\n");
    //tetrimino
    my_putstr("Tetriminos : Name 7 : Size 5*4 : Color 3 :\n");
    //tetrimino
    my_putstr("Tetriminos : Name bar : Size 1*4 : Color 2 :\n");
    //tetrimino
    my_putstr("Tetriminos : Name inverted-L : Size 2*3 : Color 5 :\n");
    //tetrimino
    my_putstr("Tetriminos : Name square : Size 2*2 : Color 1 :\n");
    //tetrimino
}