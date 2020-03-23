/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_shape_create
*/

#include <stdlib.h>
#include "tetrimino.h"
#include "my.h"

shape_t tetrimino_shape_create(uint width, uint height)
{
    shape_t shape = NULL;
    uchar square_size = 0;

    square_size = MAX(width, height);
    shape = malloc(sizeof(uchar *) * (square_size + 1));
    if (shape == NULL) {
        my_puterr("Couldn't allocate memory for tetrimino shape array.\n");
        return (NULL);
    }
    for (uint row = 0 ; row < square_size ; row++) {
        shape[row] = malloc(sizeof(uchar) * square_size);
        if (shape[row] == NULL) {
            my_puterr("Couldn't allocate memory for tetrimino shape row.\n");
            return (NULL);
        }
        for (uint col = 0 ; col < square_size ; col++)
            shape[row][col] = 0;
    }
    shape[square_size] = NULL;
    return (shape);
}