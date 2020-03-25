/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Displays the next tetrimino
*/

#include <ncurses.h>
#include "tetrimino.h"

static void display_box(int y, int x, int height, int width);

void display_next_tetrimino(tetrimino_t *tetrimino, int y, int x)
{
    mvprintw(y, x, "Next tetrimino :");
    mvprintw(y + 1, x, "\t%s", tetrimino->name);
    display_box(y + 2, x, tetrimino->height + 2, tetrimino->width + 2);
    tetrimino_display(tetrimino, y + 3, x + 2);
}

static void display_box(int y, int x, int height, int width)
{
    move(y, x);
    addch('+');
    for (int i = 0 ; i < width ; i++)
        addch('-');
    addch('+');
    for (int i = 0 ; i < height ; i++) {
        mvaddch(y + 1 + i, x, '|');
        mvaddch(y + 1 + i, x + 1 + width, '|');
    }
    move(y + height, x);
    addch('+');
    for (int i = 0 ; i < width ; i++)
        addch('-');
    addch('+');
    move(y, x);
}