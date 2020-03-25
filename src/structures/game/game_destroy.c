/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game_destroy
*/

#include <stdlib.h>
#include "game.h"

void game_destroy(game_t *game)
{
    for (uint i = 0 ; game->tetriminos[i] ; i++)
        tetrimino_destroy(game->tetriminos[i]);
    grid_destroy(game->grid);
    free(game->tetriminos);
    free(game);
}