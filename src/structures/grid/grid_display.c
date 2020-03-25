/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Displays a grid in ncurses
*/

#include <ncurses.h>
#include "grid.h"
#include "my.h"

static void grid_print_border(uint width);

void grid_display(grid_t *grid, int y, int x)
{
    move(y, x);
    grid_print_border(grid->width);
    for (uint row = 0 ; row < grid->height ; row++) {
        move(y + row + 1, x);
        addch('|');
        for (uint col = 0 ; col < grid->width ; col++) {
            attron(COLOR_PAIR(grid->cells[row][col]));
            addch(' ');
            attroff(COLOR_PAIR(grid->cells[row][col]));
        }
        addch('|');
    }
    move(y + grid->height + 1, x);
    grid_print_border(grid->width);
    move(y, x);
}

static void grid_print_border(uint width)
{
    addch('+');
    for (uint col = 0 ; col < width ; col++)
        addch('-');
    addch('+');
}