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

    shape = tetrimino_shape_create(tetrimino->size);
    if (shape == NULL)
        return (NULL);
    for (uint row = 0 ; row < tetrimino->square_size ; row++)
        for (uint col = 0 ; col < tetrimino->square_size ; col++)
            shape[row][col] = tetrimino->shape[row][col];
    shape[tetrimino->square_size] = NULL;
    return (shape);
}