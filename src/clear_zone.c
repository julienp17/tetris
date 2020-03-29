/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Clear a zone on stdscr
*/

#include <ncurses.h>

void clear_zone(int y, int x, int height, int width)
{
    attron(COLOR_PAIR(0));
    for (int row = 0 ; row < height ; row++) {
        move(y + row, x);
        for (int col = 0 ; col < width ; col++)
            addch(' ');
    }
    attroff(COLOR_PAIR(0));
}