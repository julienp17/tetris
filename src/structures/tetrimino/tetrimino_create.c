/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Returns a newly allocated tetrimino
*/

#include <stdlib.h>
#include <ncurses.h>
#include "tetrimino.h"
#include "my.h"

tetrimino_t *tetrimino_create(void)
{
    tetrimino_t *tetrimino = NULL;

    tetrimino = malloc(sizeof(tetrimino_t));
    if (tetrimino == NULL) {
        my_puterr("Couldn't allocate memory for tetrimino structure.\n");
        return (NULL);
    }
    tetrimino->name = NULL;
    tetrimino->color = COLOR_BLACK;
    tetrimino->pos = vec(0, 0);
    tetrimino->size = vec(0, 0);
    tetrimino->shape = NULL;
    tetrimino->square_size = 0;
    return (tetrimino);
}