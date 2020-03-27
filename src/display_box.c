/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Displays a box
*/

#include <ncurses.h>

static void display_border(int y, int x, int width);

void display_box(int y, int x, int height, int width)
{
    display_border(y, x, width);
    for (int i = 0 ; i < height ; i++) {
        mvaddch(y + 1 + i, x, '|');
        mvaddch(y + 1 + i, x + 1 + width, '|');
    }
    display_border(y + height + 1, x, width);
}

static void display_border(int y, int x, int width)
{
    mvaddch(y, x, '+');
    for (int i = 0 ; i < width ; i++)
        addch('-');
    addch('+');
}