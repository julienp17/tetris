/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Display the game
*/

#include <ncurses.h>
#include "game.h"

void game_display(game_t *game)
{
    int y = 0;
    int x = 0;

    getyx(stdscr, y, x);
    clear();
    grid_display(game->grid, 0, 0);
    tetrimino_display(game->tetriminos[0], y, x);
    refresh();
}