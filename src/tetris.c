/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#include <stdbool.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "game.h"
#include "my.h"
#include "tetris.h"
#include "display.h"

int game_loop(game_t *game);
int tetrimino_fall(tetrimino_t *tetrimino, clock_t *game_clock);
void refresh_game(game_t *game);
int tetrimino_move(tetrimino_t *tetrimino, grid_t *grid);

int tetris(void)
{
    game_t *game = NULL;

    game = game_create(vec(10, 20), 1);
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
    bool can_fall = false;

    refresh_game(game);
    can_fall = tetrimino_can_fall(game->current_tetrimino, game->grid);
    if (can_fall == false)
        return (-1);
    while (can_fall) {
        display_game_info(game->info, game->clock, 10, 20);
        tetrimino_fall(game->current_tetrimino, &(game->clock));
        execute_input(game->current_tetrimino, game->grid);
        can_fall = tetrimino_can_fall(game->current_tetrimino, game->grid);
        if (can_fall == false)
            grid_put_tetrimino(game->grid, game->current_tetrimino);
    }
    return (0);
}

void refresh_game(game_t *game)
{
    tetrimino_t *random_tetrimino = NULL;

    random_tetrimino = game->tetriminos[rand() % game->info->nb_tetriminos];
    game->current_tetrimino = game->next_tetrimino;
    game->next_tetrimino = tetrimino_dup(random_tetrimino);
    game->current_tetrimino->pos.x = game->grid->pos.x + game->grid->size.x / 2;
    game->current_tetrimino->pos.y = game->grid->pos.y;
    clear();
    grid_display(game->grid);
    display_next_tetrimino(game->next_tetrimino, 0, 20);
    tetrimino_display(game->current_tetrimino);
    refresh();
}

int tetrimino_fall(tetrimino_t *tetrimino, clock_t *game_clock)
{
    clock_t sec_elapsed = 0;

    sec_elapsed = (clock() / CLOCKS_PER_SEC);
    if ((sec_elapsed - (*game_clock)) >= REFRESH_TIME_SEC) {
        (*game_clock) += REFRESH_TIME_SEC;
        clear_zone(tetrimino->pos.y, tetrimino->pos.x,
                    tetrimino->size.y, tetrimino->size.x);
        tetrimino->pos.y++;
        tetrimino_display(tetrimino);
    }
    return (0);
}