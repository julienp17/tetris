/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Print a grid in ncurses
*/

#include <ncurses.h>
#include "grid.h"
#include "my.h"

void grid_print(grid_t *grid)
{
    for (uint row = 0 ; row < grid->height ; row++) {
        for (uint col = 0 ; col < grid->width ; col++)
            my_putchar(grid->cells[row][col] + '0');
        my_putchar('\n');
    }
}