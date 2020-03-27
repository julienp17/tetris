/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_can_fall
*/

#include <stdbool.h>
#include <ncurses.h>
#include "tetrimino.h"
#include "grid.h"
#include <stdio.h>

static bool collided(tetrimino_t *tetrimino, grid_t *grid, int row, int col);

bool tetrimino_can_fall(tetrimino_t *tetrimino, grid_t *grid)
{
    int y = 0;

    y = getcury(stdscr);
    if (y + tetrimino->size.y >= grid->pos.y + grid->size.y)
        return (false);
    for (int row = 0 ; row < tetrimino->size.y ; row++)
        for (int col = 0 ; col < tetrimino->size.x ; col++)
            if (collided(tetrimino, grid, row, col))
                return (false);
    return (true);
}

static bool collided(tetrimino_t *tetrimino, grid_t *grid, int row, int col)
{
    int y = 0;
    int x = 0;

    getyx(stdscr, y, x);
    return (
        tetrimino->shape[row][col] == tetrimino->color
        && row + 1 < tetrimino->size.y
        && tetrimino->shape[row + 1][col] == COLOR_BLACK
        && grid->cells[grid->pos.y + y + row][grid->pos.x + x + col] != 0
    );
}