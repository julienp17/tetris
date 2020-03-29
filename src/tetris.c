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

static int tetrimino_fall(tetrimino_t *tetrimino,clock_t *game_clock,int level);
static void clear_lines(grid_t *grid, game_info_t *info);

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
    game_refresh(game);
    if (tetrimino_can_fall(game->current_tetrimino, game->grid) == false)
        return (-1);
    while (tetrimino_can_fall(game->current_tetrimino, game->grid)) {
        display_game_info(game->info, game->clock, 10, 20);
        tetrimino_fall(game->current_tetrimino, &(game->clock),
                        game->info->level);
        execute_input(game->current_tetrimino, game->grid);
    }
    grid_put_tetrimino(game->grid, game->current_tetrimino);
    clear_lines(game->grid, game->info);
    return (0);
}

static int tetrimino_fall(tetrimino_t *tetrimino, clock_t *game_clock,int level)
{
    int delay = 0;
    clock_t sec_elapsed = 0;

    sec_elapsed = (clock() / 1000);
    delay = REFRESH_TIME - ((level - 1) * 100);
    if (delay < 500)
        delay = 500;
    if ((sec_elapsed - (*game_clock)) >= delay) {
        (*game_clock) += REFRESH_TIME;
        clear_zone(tetrimino->pos.y, tetrimino->pos.x,
                    tetrimino->size.y, tetrimino->size.x);
        tetrimino->pos.y++;
        tetrimino_display(tetrimino);
    }
    return (0);
}

static void clear_lines(grid_t *grid, game_info_t *info)
{
    int lines_removed = 0;

    info->score += 20;
    lines_removed = grid_clear_lines(grid);
    if (lines_removed > 0) {
        info->lines_removed += lines_removed;
        info->score += my_pow(2, lines_removed - 1) * 100;
        info->level = 1 + (int)(info->score / 1000);
    }
}