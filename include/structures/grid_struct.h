/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Grid structure
*/

#ifndef GRID_STRUCT_H_
    #define GRID_STRUCT_H_

    typedef unsigned int uint;
    typedef unsigned char cell_t;
    typedef struct grid {
        uint width;
        uint height;
        cell_t **cells;
    } grid_t;
#endif