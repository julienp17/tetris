/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Clear a zone on stdscr
*/

#include <ncurses.h>

void clear_zone(int y_beg, int x_beg, int y_end, int x_end)
{
    int previous_y = 0;
    int previous_x = 0;

    getyx(stdscr, previous_y, previous_x);
    attron(COLOR_PAIR(0));
    for (int row = 0 ; row < (y_end - y_beg) ; row++) {
        move(y_beg + row, x_beg);
        for (int col = 0 ; col < (x_end - x_beg) ; col++)
            addch(' ');
    }
    attroff(COLOR_PAIR(0));
    move(previous_y, previous_x);
}