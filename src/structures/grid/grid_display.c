/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Displays a grid in ncurses
*/

#include <ncurses.h>
#include "grid.h"
#include "my.h"
#include "display.h"

void grid_display(grid_t *grid)
{
    display_box(grid->pos.y - 1, grid->pos.x - 1, grid->size.y, grid->size.x);
    for (int row = 0 ; row < grid->size.y ; row++) {
        move(grid->pos.y + row, grid->pos.x);
        for (int col = 0 ; col < grid->size.x ; col++) {
            attron(COLOR_PAIR(grid->cells[row][col]));
            addch(' ');
            attroff(COLOR_PAIR(grid->cells[row][col]));
        }
    }
}