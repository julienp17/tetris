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

static cell_t **grid_create_cells(vec_t size);

grid_t *grid_create(vec_t pos, vec_t size)
{
    grid_t *grid = NULL;

    grid = malloc(sizeof(grid_t));
    if (grid == NULL) {
        my_puterr("Couldn't allocate memory for grid structure.\n");
        return (NULL);
    }
    grid->pos = pos;
    grid->size = size;
    grid->cells = grid_create_cells(size);
    if (grid->cells == NULL)
        return (NULL);
    return (grid);
}

static cell_t **grid_create_cells(vec_t size)
{
    cell_t **cells = NULL;

    cells = malloc(sizeof(cell_t *) * (size.y + 1));
    if (cells == NULL) {
        my_puterr("Couldn't allocate memory for grid structure cells.\n");
        return (NULL);
    }
    for (int row = 0 ; row < size.y ; row++) {
        cells[row] = malloc(sizeof(cell_t) * size.x);
        if (cells[row] == NULL) {
            my_puterr("Couldn't allocate memory for cells row.\n");
            return (NULL);
        }
        for (int col = 0 ; col < size.x ; col++)
            cells[row][col] = COLOR_BLACK;
    }
    cells[size.y] = NULL;
    return (cells);
}