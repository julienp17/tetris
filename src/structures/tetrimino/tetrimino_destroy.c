/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Free a tetrimino structure
*/

#include <stdlib.h>
#include "tetrimino.h"

void tetrimino_destroy(tetrimino_t *tetrimino)
{
    for (uint row = 0 ; tetrimino->shape[row] ; row++)
        free(tetrimino->shape[row]);
    free(tetrimino->shape);
    free(tetrimino->name);
    free(tetrimino);
}