/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "game.h"
#include "my.h"
#include "tetris.h"

int game_loop(game_t *game);
int tetrimino_fall(tetrimino_t *tetrimino, clock_t *game_clock);

int tetris(void)
{
    game_t *game = NULL;

    game = game_create(20, 10, 1);
    if (game == NULL)
        return (-1);
    if (ncurses_init() == -1)
        return (-1);
    while (game_loop(game) == 0);
    endwin();
    game_destroy(game);
    return (0);
}

int game_loop(game_t *game)
{
    grid_display(game->grid, 0, 0);
    display_next_tetrimino(game->next_tetrimino, 0, 20);
    move(1, game->grid->width / 2);
    tetrimino_display(game->current_tetrimino, 1, game->grid->width / 2);
    refresh();
    while (1) {
        display_game_info(game->info, game->clock, 10, 20);
        tetrimino_fall(game->current_tetrimino, &(game->clock));
        // if (tetrimino_move(current_tetrimino))
        //     game_display(game);
    }
    game->current_tetrimino = game->next_tetrimino;
    game->next_tetrimino = game->tetriminos[rand() % game->info->nb_tetriminos];
    return (0);
}

int tetrimino_fall(tetrimino_t *tetrimino, clock_t *game_clock)
{
    int y = 0;
    int x = 0;
    clock_t sec_elapsed = 0;

    sec_elapsed = (clock() / CLOCKS_PER_SEC);
    if ((sec_elapsed - (*game_clock)) >= REFRESH_TIME_SEC) {
        (*game_clock) += REFRESH_TIME_SEC;
        getyx(stdscr, y, x);
        clear_zone(y, x, y + tetrimino->height, x + tetrimino->width);
        move(y + 1, x);
        tetrimino_display(tetrimino, y + 1, x);
    }
    return (0);
}

// int tetrimino_move()
// {
//     int y = 0;
//     int x = 0;
//     int key = 0;

//     key = getch();
//     if (key == ERR)
//         return (ERR);
//     getyx(stdscr, y, x);
//     if (key == KEY_LEFT && x > 1)
//         move(y, x - 1);
//     else if (key == KEY_RIGHT && x + 2 < (int)game->grid->width)
//         move(y, x + 1);
//     return (0);
// }