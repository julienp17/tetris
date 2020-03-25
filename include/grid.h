/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Grid structure
*/

#ifndef GRID_H_
    #define GRID_H_

    typedef unsigned int uint;
    typedef unsigned char cell_t;
    typedef struct grid {
        uint width;
        uint height;
        cell_t **cells;
    } grid_t;

    grid_t *grid_create(uint height, uint width);
    void grid_destroy(grid_t *grid);
    void grid_display(grid_t *grid, int y, int x);
#endif