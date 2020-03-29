/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

    #include <time.h>
    #include "grid.h"
    #include "tetrimino.h"
    #include "game_info.h"

    #define REFRESH_TIME        1000

    typedef unsigned int uint;
    typedef struct game {
        grid_t *grid;
        tetrimino_t **tetriminos;
        tetrimino_t *current_tetrimino;
        tetrimino_t *next_tetrimino;
        clock_t clock;
        game_info_t *info;
    } game_t;

    game_t *game_create(vec_t size, int level);
    void game_destroy(game_t *game);

    void game_refresh(game_t *game);
#endif