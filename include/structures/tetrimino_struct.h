/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_struct
*/

#ifndef TETRIMINO_STRUCT_H_
    #define TETRIMINO_STRUCT_H_

    typedef unsigned char uchar;
    typedef unsigned char **shape_t;
    typedef struct tetrimino {
        char *name;
        uchar height;
        uchar width;
        uchar color;
        shape_t shape;
    } tetrimino_t;
#endif