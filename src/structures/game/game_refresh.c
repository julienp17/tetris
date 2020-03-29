/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** game_refresh
*/

#include <stdlib.h>
#include <ncurses.h>
#include "display.h"
#include "game.h"

void game_refresh(game_t *game)
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