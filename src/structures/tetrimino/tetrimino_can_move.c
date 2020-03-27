/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Tetrimino_can_move
*/

#include <stdbool.h>
#include "tetrimino.h"
#include "grid.h"

bool tetrimino_can_move(tetrimino_t *tetrimino, grid_t *grid, int offset)
{
    int new_pos = 0;
    vec_t cell;

    new_pos = tetrimino->pos.x + offset;
    if (new_pos < grid->pos.x)
        return (false);
    if (new_pos + tetrimino->size.x > grid->pos.x + grid->size.x)
        return (false);
    cell.x = tetrimino->pos.x - grid->pos.x;
    cell.y = tetrimino->pos.y - grid->pos.y;
    for (int row = 0 ; row < tetrimino->size.y ; row++) {
        if (offset < 0 && grid->cells[cell.y + row][cell.x - 1] != 0)
            return (false);
        if (offset > 0 &&
            grid->cells[cell.y + row][cell.x + tetrimino->size.x] != 0)
            return (false);
    }
    return (true);
}