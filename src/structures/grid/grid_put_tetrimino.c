/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Put a tetrimino in a grid
*/

#include "grid.h"
#include "tetrimino.h"

void grid_put_tetrimino(grid_t *grid, tetrimino_t *tetrimino)
{
    vec_t pos = tetrimino->pos;
    shape_t shape = tetrimino->shape;

    pos.x -= grid->pos.x;
    pos.y -= grid->pos.y;
    for (int row = 0 ; row < tetrimino->size.y ; row++)
        for (int col = 0 ; col < tetrimino->size.x ; col++)
            if (tetrimino->shape[row][col] == tetrimino->color)
                grid->cells[pos.y + row][pos.x + col] = shape[row][col];
}