/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_create
*/

#include <stdlib.h>
#include "tetrimino.h"

tetrimino_t *tetrimino_create(char const *name, shape_t shape)
{
    tetrimino_t *tetrimino = NULL;

    tetrimino = malloc(sizeof(tetrimino_t));
    if (tetrimino == NULL) {
        my_puterr("Couldn't allocate memory for tetrimino structure.\n");
        return (NULL);
    }
    tetrimino->width = 0;
    tetrimino->height = 0;
    tetrimino->color = 0;
    tetrimino->name = my_strdup(name);
    tetrimino->shape = NULL;
    return (tetrimino);
}