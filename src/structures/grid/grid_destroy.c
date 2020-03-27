/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** grid_destroy
*/

#include <stdlib.h>
#include "grid.h"

void grid_destroy(grid_t *grid)
{
    for (int row = 0 ; row < grid->size.y ; row++)
        free(grid->cells[row]);
    free(grid->cells);
    free(grid);
}