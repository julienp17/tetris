/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino
*/

#ifndef TETRIMINO_H_
    #define TETRIMINO_H_

    #include "orientation_enum.h"

    #define MAX(nb1, nb2) ((nb1 > nb2 ? nb1 : nb2))
    #define SQUARE_CHAR     '*'
    #define TETRIMINOS_DIR_PATH     "tetriminos/"

    typedef unsigned char uchar;
    typedef unsigned char **shape_t;
    typedef struct tetrimino {
        char *name;
        uchar height;
        uchar width;
        uchar color;
        shape_t shape;
    } tetrimino_t;

    typedef unsigned  int uint;

    tetrimino_t *tetrimino_create_from_file(char const *filename);
    void tetrimino_destroy(tetrimino_t *tetrimino);

    shape_t tetrimino_shape_create(uint width, uint height);
    shape_t tetrimino_shape_dup(tetrimino_t const *tetrimino);

    void tetrimino_rotate(tetrimino_t *tetrimino, orientation_t orientation);
    void tetrimino_display(tetrimino_t *tetrimino, int y, int x);

    tetrimino_t **get_tetriminos_from_dir(char const *dir_path);
#endif