/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Grid structure
*/

#ifndef GRID_H_
    #define GRID_H_

    #include "grid_struct.h"

    grid_t *grid_create(uint width, uint height);
    void grid_destroy(grid_t *grid);
    void grid_print(grid_t *grid);
#endif