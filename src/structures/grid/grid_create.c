/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** grid_create
*/

#include <stdlib.h>
#include <ncurses.h>
#include "grid.h"
#include "my.h"

static cell_t **grid_create_cells(uint height, uint width);

grid_t *grid_create(uint height, uint width)
{
    grid_t *grid = NULL;

    grid = malloc(sizeof(grid_t));
    if (grid == NULL) {
        my_puterr("Couldn't allocate memory for grid structure.\n");
        return (NULL);
    }
    grid->width = width;
    grid->height = height;
    grid->cells = grid_create_cells(height, width);
    if (grid->cells == NULL)
        return (NULL);
    return (grid);
}

static cell_t **grid_create_cells(uint height, uint width)
{
    cell_t **cells = NULL;

    cells = malloc(sizeof(cell_t *) * (height + 1));
    if (cells == NULL) {
        my_puterr("Couldn't allocate memory for grid structure cells.\n");
        return (NULL);
    }
    for (uint row = 0 ; row < height ; row++) {
        cells[row] = malloc(sizeof(cell_t) * width);
        if (cells[row] == NULL) {
            my_puterr("Couldn't allocate memory for cells row.\n");
            return (NULL);
        }
        for (uint col = 0 ; col < width ; col++)
            cells[row][col] = COLOR_BLACK;
    }
    cells[height] = NULL;
    return (cells);
}