/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Displays the next tetrimino
*/

#include <ncurses.h>
#include "tetrimino.h"
#include "tetris.h"

void display_next_tetrimino(tetrimino_t *tetrimino, int y, int x)
{
    mvprintw(y, x, "Next tetrimino :");
    mvprintw(y + 1, x, "\t%s", tetrimino->name);
    display_box(y + 2, x, tetrimino->height + 2, tetrimino->width + 2);
    tetrimino_display(tetrimino, y + 3, x + 2);
}