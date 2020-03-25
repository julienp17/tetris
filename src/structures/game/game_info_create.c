/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game_info_create
*/

#include <stdlib.h>
#include "game_info.h"
#include "tetrimino.h"
#include "file_reading.h"
#include "my.h"

static int get_high_score(void);

game_info_t *game_info_create(int level, tetrimino_t **tetrominos)
{
    game_info_t *game_info = NULL;

    game_info = malloc(sizeof(game_info_t));
    if (game_info == NULL) {
        my_puterr("Couldn't allocate memory for game_info structure.\n");
        return (NULL);
    }
    game_info->score = 0;
    game_info->high_score = get_high_score();
    game_info->level = level;
    game_info->lines_removed = 0;
    game_info->nb_tetriminos = 0;
    for (; tetrominos[game_info->nb_tetriminos] ; game_info->nb_tetriminos++);
    return (game_info);
}

static int get_high_score(void)
{
    char *file_buffer = 0;
    int high_score = 0;

    file_buffer = get_file_buffer(HIGH_SCORE_PATH);
    if (file_buffer == NULL)
        return (-1);
    high_score = my_atoi(file_buffer);
    return (high_score);
}