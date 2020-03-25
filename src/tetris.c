/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#include <ncurses.h>
#include <time.h>
#include "game.h"
#include "my.h"
#include "tetris.h"

int game_loop(game_t *game);

int tetris(void)
{
    game_t *game = NULL;

    game = game_create(20, 10);
    if (game == NULL)
        return (-1);
    if (ncurses_init() == -1)
        return (-1);
    move(1, game->grid->width / 2);
    while (game_loop(game) == 0);
    endwin();
    game_destroy(game);
    return (0);
}

int game_loop(game_t *game)
{
    int y = 0;
    int x = 0;
    int key = 0;
    clock_t sec_elapsed = 0;

    getyx(stdscr, y, x);
    sec_elapsed = (clock() / CLOCKS_PER_SEC);
    if ((sec_elapsed - game->clock) >= REFRESH_TIME_SEC) {
        game->clock += REFRESH_TIME_SEC;
        move(y + 1, x);
        game_display(game);
    }
    key = getch();
    if (key == KEY_LEFT && x > 1) {
        move(y, x - 1);
        game_display(game);
    } else if (key == KEY_RIGHT && x + 2 < (int)game->grid->width) {
        move(y, x + 1);
        game_display(game);
    }
    return (0);
}