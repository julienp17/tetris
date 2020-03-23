/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Print a grid in ncurses
*/

#include <ncurses.h>
#include "grid.h"
#include "my.h"

static void grid_print_border(uint width);

void grid_print(grid_t *grid)
{
    grid_print_border(grid->width);
    for (uint row = 0 ; row < grid->height ; row++) {
        addch('|');
        for (uint col = 0 ; col < grid->width ; col++) {
            attron(COLOR_PAIR(grid->cells[row][col]));
            addch(' ');
            attroff(COLOR_PAIR(grid->cells[row][col]));
        }
        addch('|');
        addch('\n');
    }
    grid_print_border(grid->width);
    refresh();
}

static void grid_print_border(uint width)
{
    addch('+');
    for (uint col = 0 ; col < width ; col++)
        addch('-');
    addch('+');
    addch('\n');
}