/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display
*/

#ifndef DISPLAY_H_
    #define DISPLAY_H_

    #include <time.h>
    #include "tetrimino.h"
    #include "game_info.h"

    void clear_zone(int y, int x, int height, int width);
    void display_box(int y, int x, int height, int width);
    void display_next_tetrimino(tetrimino_t *tetrimino, int y, int x);
    void display_game_info(game_info_t *game_info, clock_t game_clock,
                            int y, int x);
#endif