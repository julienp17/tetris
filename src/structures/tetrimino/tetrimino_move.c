/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetrimino_move
*/

#include <ncurses.h>
#include "tetrimino.h"
#include "grid.h"
#include "display.h"

int tetrimino_move(tetrimino_t *tetrimino, grid_t *grid)
{
    int key = 0;

    key = getch();
    if (key == ERR || (key != KEY_LEFT && key != KEY_RIGHT))
        return (ERR);
    clear_zone(tetrimino->pos.y, tetrimino->pos.x,
                tetrimino->size.y, tetrimino->size.x);
    if (key == KEY_LEFT && tetrimino->pos.x - 1 >= grid->pos.x) {
        tetrimino->pos.x--;
    }
    if (key == KEY_RIGHT && tetrimino->pos.x + tetrimino->size.x + 1
                            <= grid->pos.x + grid->size.x) {
        tetrimino->pos.x++;
    }
    tetrimino_display(tetrimino);
    return (0);
}