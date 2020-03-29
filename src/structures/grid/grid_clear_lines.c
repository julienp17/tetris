/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Remove completed lines from grid
*/

#include <stdbool.h>
#include <ncurses.h>
#include "grid.h"

static bool row_is_full(grid_t *grid, int row);
static void remove_row(grid_t *grid, int row);

int grid_clear_lines(grid_t *grid)
{
    int cleared_lines = 0;

    for (int row = 0 ; row < grid->size.y ; row++) {
        if (row_is_full(grid, row)) {
            remove_row(grid, row);
            cleared_lines++;
        }
    }
    return (cleared_lines);
}

static bool row_is_full(grid_t *grid, int row)
{
    for (int col = 0 ; col < grid->size.x ; col++)
        if (grid->cells[row][col] == 0)
            return (false);
    return (true);
}

static void remove_row(grid_t *grid, int row)
{
    for (int y = row ; y > 0 ; y--)
        for (int col = 0 ; col < grid->size.x ; col++)
            grid->cells[y][col] = grid->cells[y - 1][col];
}