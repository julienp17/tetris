/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** tetris
*/

#ifndef TETRIS_H_
    #define TETRIS_H_

    int tetris(void);
    int ncurses_init(void);

    void clear_zone(int y_beg, int x_beg, int y_end, int x_end);
    void display_next_tetrimino(tetrimino_t *tetrimino, int y, int x);
#endif