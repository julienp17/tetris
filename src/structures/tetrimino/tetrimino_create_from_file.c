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

static shape_t tetrimino_shape_create(tetrimino_t *tetrimino);
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
    tetrimino->width  = my_strtol(file_lines[0], &(file_lines[0]));
    tetrimino->height = my_strtol(file_lines[0], &(file_lines[0]));
    tetrimino->color  = my_strtol(file_lines[0], &(file_lines[0]));
    tetrimino->shape  = tetrimino_shape_create(tetrimino);
    tetrimino_shape_fill_from_lines(tetrimino, file_lines + 1);
    return (tetrimino->shape == NULL ? NULL : tetrimino);
}

static shape_t tetrimino_shape_create(tetrimino_t *tetrimino)
{
    shape_t shape = NULL;
    uchar nb_rows = 0;

    nb_rows = MAX(tetrimino->height, tetrimino->width);
    shape = malloc(sizeof(uchar *) * (nb_rows + 1));
    if (shape == NULL) {
        my_puterr("Couldn't allocate memory for tetrimino shape array.\n");
        return (NULL);
    }
    for (uint row = 0 ; row < nb_rows ; row++) {
        shape[row] = malloc(sizeof(uchar) * tetrimino->width);
        if (shape[row] == NULL) {
            my_puterr("Couldn't allocate memory for tetrimino shape row.\n");
            return (NULL);
        }
        for (uint col = 0 ; col < tetrimino->width ; col++)
            shape[row][col] = 0;
    }
    shape[nb_rows] = NULL;
    return (shape);
}

static void tetrimino_shape_fill_from_lines(tetrimino_t *tetrimino,
                                            char **file_lines)
{
    for (uint row = 0 ; file_lines[row] ; row++)
        for (uint col = 0 ; file_lines[row][col] ; col++)
            if (file_lines[row][col] == SQUARE_CHAR)
                tetrimino->shape[row][col] = tetrimino->color;
}