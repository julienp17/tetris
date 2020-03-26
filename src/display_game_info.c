/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** display_game_info
*/

#include <ncurses.h>
#include <time.h>
#include "game_info.h"
#include "tetris.h"

void display_game_info(game_info_t *game_info, clock_t game_clock, int y, int x)
{
    int previous_y = 0;
    int previous_x = 0;

    getyx(stdscr, previous_y, previous_x);
    mvprintw(y, x, "Game info");
    display_box(y + 1, x, 10, 20);
    mvprintw(y + 2, x + 1, "High Score : %d", game_info->high_score);
    mvprintw(y + 4, x + 1, "Score : %d", game_info->score);
    mvprintw(y + 6, x + 1, "Level : %d", game_info->level);
    mvprintw(y + 8, x + 1, "Lines removed : %d", game_info->lines_removed);
    mvprintw(y + 10, x + 1, "Timer : %d", game_clock);
    move(previous_y, previous_x);
}