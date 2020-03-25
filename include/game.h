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

    #define REFRESH_TIME_SEC        1

    typedef struct game {
        grid_t *grid;
        tetrimino_t **tetriminos;
        clock_t clock;
    } game_t;

    game_t *game_create(uint height, uint width);
    void game_destroy(game_t *game);

    void game_display(game_t *game);
#endif