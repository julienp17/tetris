/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#ifndef TETRIS_H_
    #define TETRIS_H_

    #include <stdbool.h>
    #include "game.h"

    #define USAGE \
    "Options:\n" \
    " --help               Display this help\n" \
    " -L --level={num}     Start Tetris at level num (def: 1)\n" \
    " -l --key-left={K}    Move the tetrimino LEFT using the K key (def: left arrow)\n" \
    " -r --key-right={K}   Move the tetrimino RIGHT using the K key (def: right arrow)\n" \
    " -t --key-turn={K}    TURN the tetrimino clockwise 90d using the K key (def: top\n" \
    "arrow)\n" \
    " -d --key-drop={K}    DROP the tetrimino using the K key (def: down arrow)\n" \
    " -q --key-quit={K}    QUIT the game using the K key (def: ‘q’ key)\n" \
    " -p --key-pause={K}   PAUSE/RESTART the game using the K key (def: space bar)\n" \
    " --map-size={row,col} Set the numbers of rows and columns of the map (def: 20,10)\n" \
    " -w --without-next    Hide next tetrimino (def: false)\n" \
    " -D --debug           Debug mode (def: false)\n" \

    int tetris(void);
    int ncurses_init(void);

    int game_loop(game_t *game);
    void refresh_game(game_t *game);
    int execute_input(tetrimino_t *tetrimino, grid_t *grid);

    bool tetrimino_can_fall(tetrimino_t *tetrimino, grid_t *grid);
    bool tetrimino_can_rotate(tetrimino_t *tetrimino, grid_t *grid);
    bool tetrimino_can_move(tetrimino_t *tetrimino, grid_t *grid, int offset);
    int tetrimino_move(tetrimino_t *tetrimino, grid_t *grid);

    bool print_help(int ac, char **av);
#endif