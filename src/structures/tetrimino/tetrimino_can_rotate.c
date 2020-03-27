/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Returns true if a tetrimino can rotate, false otherwise
*/

#include <stdbool.h>
#include "tetrimino.h"
#include "grid.h"

bool tetrimino_can_rotate(tetrimino_t *tetrimino, grid_t *grid)
{
    return (
        tetrimino->pos.x + tetrimino->size.y <= grid->pos.x + grid->size.x
        && tetrimino->pos.y + tetrimino->size.x <= grid->pos.y + grid->size.y
    );
}