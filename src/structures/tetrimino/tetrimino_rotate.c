/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_rotate
*/

#include <stdlib.h>
#include "tetrimino.h"
#include "my.h"

static void tetrimino_rotate_right(tetrimino_t *tetrimino, shape_t shape_dup);
static bool col_is_empty(shape_t shape);

void tetrimino_rotate(tetrimino_t *tetrimino)
{
    shape_t shape_dup = NULL;

    shape_dup = tetrimino_shape_dup(tetrimino);
    if (shape_dup == NULL)
        return;
    tetrimino_rotate_right(tetrimino, shape_dup);
    my_swap_int(&(tetrimino->size.x), &(tetrimino->size.y));
    for (uint i = 0 ; shape_dup[i] ; i++)
        free(shape_dup[i]);
    free(shape_dup);
}

static void tetrimino_rotate_right(tetrimino_t *tetrimino, shape_t shape_dup)
{
    uint square_size = 0;
    uchar new_value = 0;

    square_size = MAX(tetrimino->size.x, tetrimino->size.y);
    for (uint row = 0 ; row < square_size ; row++) {
        for (uint col = 0 ; col < square_size ; col++) {
            new_value = shape_dup[square_size - 1 - col][row];
            tetrimino->shape[row][col] = new_value;
        }
    }
    if (!col_is_empty(tetrimino->shape))
        return;
    for (uint col = 0 ; col < square_size ; col++) {
        for (uint row = 0 ; row < square_size ; row++) {
            if (col < square_size - 1)
                tetrimino->shape[row][col] = tetrimino->shape[row][col + 1];
            else
                tetrimino->shape[row][col] = 0;
        }
    }
}

static bool col_is_empty(shape_t shape)
{
    for (uint row = 0 ; shape[row] ; row++)
        if (shape[row][0] != 0)
            return (false);
    return (true);
}