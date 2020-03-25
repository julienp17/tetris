/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game_info
*/

#ifndef GAME_INFO_H_
    #define GAME_INFO_H_

    #define HIGH_SCORE_PATH     ".high_score"

    #include "tetrimino.h"

    typedef unsigned int uint;
    typedef struct game_info {
        uint nb_tetriminos;
        uint lines_removed;
        int score;
        int high_score;
        int level;
    } game_info_t;

    game_info_t *game_info_create(int level, tetrimino_t **tetrominos);
#endif