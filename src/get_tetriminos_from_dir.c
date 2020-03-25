/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Return an array of tetriminos from a dir
*/

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include "file_reading.h"
#include "tetrimino.h"
#include "my.h"

static tetrimino_t **tetriminos_allocate(char const *dir_path);
static void tetriminos_fill_from_dir(tetrimino_t **tetriminos, DIR *dir,
                                    char const *dir_path);

tetrimino_t **get_tetriminos_from_dir(char const *dir_path)
{
    tetrimino_t **tetriminos = NULL;
    DIR *dir = NULL;

    tetriminos = tetriminos_allocate(dir_path);
    if (tetriminos == NULL)
        return (NULL);
    dir = opendir(dir_path);
    if (dir == NULL) {
        perror(dir_path);
        return (NULL);
    }
    tetriminos_fill_from_dir(tetriminos, dir, dir_path);
    if (closedir(dir) != 0) {
        perror(dir_path);
        return (NULL);
    }
    return (tetriminos);
}

static tetrimino_t **tetriminos_allocate(char const *dir_path)
{
    tetrimino_t **tetriminos = NULL;
    int nb_tetriminos = 0;

    nb_tetriminos = get_nb_files_in_dir(dir_path);
    if (nb_tetriminos < 0)
        return (NULL);
    tetriminos = malloc(sizeof(tetrimino_t *) * (nb_tetriminos + 1));
    if (tetriminos == NULL) {
        my_puterr("Couldn't allocate memory for tetriminos array.\n");
        return (NULL);
    }
    tetriminos[nb_tetriminos] = NULL;
    return (tetriminos);
}

static void tetriminos_fill_from_dir(tetrimino_t **tetriminos, DIR *dir,
                                    char const *dir_path)
{
    char *file_name = NULL;
    char *file_path = NULL;
    struct dirent *dir_entry = NULL;
    uint tetrimino_index = 0;

    while ((dir_entry = readdir(dir)) != NULL) {
        file_name = dir_entry->d_name;
        if (my_strcmp(file_name, ".") == 0 || my_strcmp(file_name, "..") == 0)
            continue;
        file_path = my_strdupcat(dir_path, file_name);
        tetriminos[tetrimino_index] = tetrimino_create_from_file(file_path);
        tetrimino_index++;
    }
}