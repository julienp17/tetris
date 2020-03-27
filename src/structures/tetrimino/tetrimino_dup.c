/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Duplicate a tetrimino_pointer
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "tetrimino.h"
#include "my.h"

tetrimino_t *tetrimino_dup(tetrimino_t const *tetrimino)
{
    tetrimino_t *tetrimino_dup = NULL;

    tetrimino_dup = tetrimino_create();
    if (tetrimino_dup == NULL)
        return (NULL);
    tetrimino_dup->name  = my_strdup(tetrimino->name);
    tetrimino_dup->color = tetrimino->color;
    tetrimino_dup->pos   = tetrimino->pos;
    tetrimino_dup->size  = tetrimino->size;
    tetrimino_dup->square_size = tetrimino->square_size;
    tetrimino_dup->shape = tetrimino_shape_dup(tetrimino);
    return (tetrimino_dup);
}