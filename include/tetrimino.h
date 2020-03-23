/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino
*/

#ifndef TETRIMINO_H_
    #define TETRIMINO_H_

    #include "tetrimino_struct.h"

    #define MAX(nb1, nb2) ((nb1 > nb2 ? nb1 : nb2))
    #define SQUARE_CHAR     '*'

    typedef unsigned  int uint;

    tetrimino_t *tetrimino_create(char const *name, shape_t shape);
    tetrimino_t *tetrimino_create_from_file(char const *filename);
    void tetrimino_print(tetrimino_t *tetrimino);
#endif