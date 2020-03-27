/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Grid structure
*/

#ifndef GRID_H_
    #define GRID_H_

    #include "vector.h"

    typedef unsigned int uint;
    typedef unsigned char cell_t;
    typedef struct grid {
        cell_t **cells;
        vec_t pos;
        vec_t size;
    } grid_t;

    grid_t *grid_create(vec_t pos, vec_t size);
    void grid_destroy(grid_t *grid);
    void grid_display(grid_t *grid);
#endif