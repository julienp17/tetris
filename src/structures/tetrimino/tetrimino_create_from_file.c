/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_create_from_file
*/

#include <stdlib.h>
#include "file_reading.h"
#include "tetrimino.h"
#include "my.h"

static void tetrimino_shape_fill_from_lines(tetrimino_t *tetrimino,
                                            char **file_lines);

tetrimino_t *tetrimino_create_from_file(char const *filename)
{
    tetrimino_t *tetrimino = NULL;
    char **file_lines = NULL;

    tetrimino = malloc(sizeof(tetrimino_t));
    if (tetrimino == NULL) {
        my_puterr("Couldn't allocate memory for tetrimino structure.\n");
        return (NULL);
    }
    file_lines = get_file_lines(filename);
    if (file_lines == NULL)
        return (NULL);
    tetrimino->name   = my_strdup(filename);
    tetrimino->size.x = my_strtol(file_lines[0], &(file_lines[0]));
    tetrimino->size.y = my_strtol(file_lines[0], &(file_lines[0]));
    tetrimino->square_size = MAX(tetrimino->size.x, tetrimino->size.y);
    tetrimino->pos    = vec(0, 0);
    tetrimino->color  = my_strtol(file_lines[0], &(file_lines[0]));
    tetrimino->shape  = tetrimino_shape_create(tetrimino->size);
    tetrimino_shape_fill_from_lines(tetrimino, file_lines + 1);
    return (tetrimino->shape == NULL ? NULL : tetrimino);
}

static void tetrimino_shape_fill_from_lines(tetrimino_t *tetrimino,
                                            char **file_lines)
{
    for (uint row = 0 ; file_lines[row] ; row++)
        for (uint col = 0 ; file_lines[row][col] ; col++)
            if (file_lines[row][col] == SQUARE_CHAR)
                tetrimino->shape[row][col] = tetrimino->color;
}