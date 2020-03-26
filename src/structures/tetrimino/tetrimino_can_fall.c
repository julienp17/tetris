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

static bool collided(tetrimino_t *tetrimino, grid_t *grid, uint row, uint col);

bool tetrimino_can_fall(tetrimino_t *tetrimino, grid_t *grid)
{
    uchar square_size = 0;
    int y = 0;
    int _ = 0;

    getyx(stdscr, y, _);
    (void)_;
    if (y - 1 + tetrimino->height >= (int)grid->height)
        return (false);
    square_size = MAX(tetrimino->height, tetrimino->width);
    for (uint row = 0 ; row < square_size ; row++)
        for (uint col = 0 ; col < square_size ; col++)
            if (collided(tetrimino, grid, row, col))
                return (false);
    return (true);
}

static bool collided(tetrimino_t *tetrimino, grid_t *grid, uint row, uint col)
{
    int y = 0;
    int x = 0;
    uchar square_size = 0;

    square_size = MAX(tetrimino->height, tetrimino->width);
    getyx(stdscr, y, x);
    y--;
    x--;
    return (
        tetrimino->shape[row][col] == tetrimino->color
        && row + 1 < square_size
        && tetrimino->shape[row + 1][col] == COLOR_BLACK
        && grid->cells[y + row][x + col] != COLOR_BLACK
    );
}