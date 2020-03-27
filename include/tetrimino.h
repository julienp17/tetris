/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino
*/

#ifndef TETRIMINO_H_
    #define TETRIMINO_H_

    #include <stdbool.h>
    #include "vector.h"
    #include "grid.h"
    #include "orientation_enum.h"

    #define MAX(nb1, nb2) ((nb1 > nb2 ? nb1 : nb2))
    #define SQUARE_CHAR     '*'
    #define TETRIMINOS_DIR_PATH     "tetriminos/"

    typedef unsigned char uchar;
    typedef unsigned char **shape_t;
    typedef struct tetrimino {
        char *name;
        uchar color;
        vec_t pos;
        vec_t size;
        uint square_size;
        shape_t shape;
    } tetrimino_t;

    typedef unsigned  int uint;

    tetrimino_t *tetrimino_create_from_file(char const *filename);
    void tetrimino_destroy(tetrimino_t *tetrimino);
    bool tetrimino_can_fall(tetrimino_t *tetrimino, grid_t *grid);

    shape_t tetrimino_shape_create(vec_t size);
    shape_t tetrimino_shape_dup(tetrimino_t const *tetrimino);

    void tetrimino_rotate(tetrimino_t *tetrimino, orientation_t orientation);
    void tetrimino_display(tetrimino_t *tetrimino);

    tetrimino_t **get_tetriminos_from_dir(char const *dir_path);
#endif