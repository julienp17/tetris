/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_print
*/

#include <ncurses.h>
#include "tetrimino.h"

void tetrimino_print(tetrimino_t *tetrimino)
{
    uchar square_size = 0;

    square_size = MAX(tetrimino->height, tetrimino->width);
    for (uint row = 0 ; row < square_size ; row++) {
        for (uint col = 0 ; col < square_size ; col++) {
            if (tetrimino->shape[row][col] == tetrimino->color) {
                attron(COLOR_PAIR(tetrimino->color));
                addch(' ');
                attroff(COLOR_PAIR(tetrimino->color));
            } else {
                addch(' ');
            }
        }
        addch('\n');
    }
    refresh();
}