/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Displays the next tetrimino
*/

#include <ncurses.h>
#include "tetrimino.h"
#include "display.h"

void display_next_tetrimino(tetrimino_t *tetrimino, int y, int x)
{
    mvprintw(y, x, "Next tetrimino :");
    mvprintw(y + 1, x, "\t%s", tetrimino->name);
    display_box(y + 2, x, tetrimino->size.x + 2, tetrimino->size.y + 2);
    tetrimino->pos.x = x + 2;
    tetrimino->pos.y = y + 3;
    tetrimino_display(tetrimino);
}