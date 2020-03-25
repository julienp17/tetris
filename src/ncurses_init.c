/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Initialize ncurses mode
*/

#include <stddef.h>
#include <ncurses.h>
#include "my.h"

static void ncurses_init_pairs(void);

int ncurses_init(void)
{
    if (initscr() == NULL) {
        my_puterr("Couldn't allocate memory for stdscr.\n");
        return (-1);
    };
    if (has_colors() == FALSE) {
        endwin();
        my_puterr("Your terminal does not support color. Exiting...\n");
        return (-1);
    }
    noecho();
    cbreak();
    start_color();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    ncurses_init_pairs();
    return (0);
}

static void ncurses_init_pairs(void)
{
    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_WHITE, COLOR_GREEN);
    init_pair(3, COLOR_WHITE, COLOR_YELLOW);
    init_pair(4, COLOR_WHITE, COLOR_BLUE);
    init_pair(5, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(6, COLOR_WHITE, COLOR_CYAN);
    init_pair(7, COLOR_BLACK, COLOR_WHITE);
}