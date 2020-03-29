/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** get_input
*/

#include <ncurses.h>
#include <stdlib.h>
#include "tetrimino.h"
#include "grid.h"
#include "display.h"
#include "tetris.h"

int execute_input(tetrimino_t *tetrimino, grid_t *grid)
{
    int key = 0;

    key = getch();
    if (key == ERR)
        return (ERR);
    if (key == 'q') {
        endwin();
        exit(0);
    }
    clear_zone(tetrimino->pos.y, tetrimino->pos.x,
                tetrimino->size.y, tetrimino->size.x);
    if (key == KEY_LEFT && tetrimino_can_move(tetrimino, grid, -1))
        tetrimino->pos.x--;
    if (key == KEY_RIGHT && tetrimino_can_move(tetrimino, grid, 1))
        tetrimino->pos.x++;
    if (key == KEY_DOWN)
        tetrimino->pos.y++;
    if (key == KEY_UP && tetrimino_can_rotate(tetrimino, grid))
        tetrimino_rotate(tetrimino);
    tetrimino_display(tetrimino);
    return (0);
}