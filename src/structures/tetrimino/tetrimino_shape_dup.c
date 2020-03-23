/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_shape_dup
*/

#include <stdlib.h>
#include "tetrimino.h"
#include "my.h"

shape_t tetrimino_shape_dup(tetrimino_t const *tetrimino)
{
    shape_t shape = NULL;
    uchar square_size = 0;

    shape = tetrimino_shape_create(tetrimino->width, tetrimino->height);
    if (shape == NULL)
        return (NULL);
    square_size = MAX(tetrimino->width, tetrimino->height);
    for (uint row = 0 ; row < square_size ; row++)
        for (uint col = 0 ; col < square_size ; col++)
            shape[row][col] = tetrimino->shape[row][col];
    shape[square_size] = NULL;
    return (shape);
}