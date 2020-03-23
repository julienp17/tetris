/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_rotate
*/

#include <stdlib.h>
#include "orientation_enum.h"
#include "tetrimino.h"

static void tetrimino_rotate_right(tetrimino_t *tetrimino, shape_t shape_dup);
static void tetrimino_rotate_left(tetrimino_t *tetrimino, shape_t shape_dup);

void tetrimino_rotate(tetrimino_t *tetrimino, orientation_t orientation)
{
    shape_t shape_dup = NULL;
    uchar tmp = tetrimino->height;

    shape_dup = tetrimino_shape_dup(tetrimino);
    if (shape_dup == NULL)
        return;
    if (orientation == LEFT)
        tetrimino_rotate_left(tetrimino, shape_dup);
    else
        tetrimino_rotate_right(tetrimino, shape_dup);
    tetrimino->height = tetrimino->width;
    tetrimino->width = tmp;
    for (uint i = 0 ; shape_dup[i] ; i++)
        free(shape_dup[i]);
    free(shape_dup);
}

static void tetrimino_rotate_right(tetrimino_t *tetrimino, shape_t shape_dup)
{
    uint square_size = 0;
    uchar new_value = 0;

    square_size = MAX(tetrimino->height, tetrimino->width);
    for (uint row = 0 ; row < square_size ; row++) {
        for (uint col = 0 ; col < square_size ; col++) {
            new_value = shape_dup[square_size - 1 - col][row];
            tetrimino->shape[row][col] = new_value;
        }
    }
}

static void tetrimino_rotate_left(tetrimino_t *tetrimino, shape_t shape_dup)
{
    uint square_size = 0;
    uchar new_value = 0;

    square_size = MAX(tetrimino->height, tetrimino->width);
    for (uint row = 0 ; row < square_size ; row++) {
        for (uint col = 0 ; col < square_size ; col++) {
            new_value = shape_dup[col][square_size - 1 - row];
            tetrimino->shape[row][col] = new_value;
        }
    }
}