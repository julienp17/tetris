/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Display a tetrimino
*/

#include <ncurses.h>
#include "tetrimino.h"

void tetrimino_display(tetrimino_t *tetrimino)
{
    int y = 0;
    int x = 0;

    getyx(stdscr, y, x);
    for (uint row = 0 ; row < tetrimino->square_size ; row++) {
        move(y + row, x);
        for (uint col = 0 ; col < tetrimino->square_size ; col++) {
            if (tetrimino->shape[row][col] == tetrimino->color) {
                attron(COLOR_PAIR(tetrimino->color));
                addch(' ');
                attroff(COLOR_PAIR(tetrimino->color));
            } else {
                addch(' ');
            }
        }
    }
}