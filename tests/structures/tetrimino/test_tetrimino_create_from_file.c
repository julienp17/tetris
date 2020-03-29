/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_tetrimino_create_from_file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ncurses.h>
#include "tetrimino.h"

Test(tetrimino_create_from_file, snake)
{
    tetrimino_t *tetrimino = NULL;
    char const tetrimino_path[] = "tetriminos/snake.tetrimino";
    unsigned char expected_shape[2][3] = {
        {COLOR_BLACK, COLOR_GREEN, COLOR_GREEN},
        {COLOR_GREEN, COLOR_GREEN, COLOR_BLACK},
    };

    tetrimino = tetrimino_create_from_file(tetrimino_path);
    cr_assert_not_null(tetrimino);
    cr_assert_str_eq(tetrimino->name, "snake");
    cr_assert_eq(tetrimino->size.x, 3);
    cr_assert_eq(tetrimino->size.y, 2);
    cr_assert_eq(tetrimino->square_size, 3);
    cr_assert_eq(tetrimino->pos.x, 0);
    cr_assert_eq(tetrimino->pos.y, 0);
    cr_assert_eq(tetrimino->color, COLOR_GREEN);
    for (int row = 0 ; row < tetrimino->size.y ; row++)
        for (int col = 0 ; col < tetrimino->size.x ; col++)
            cr_assert_eq(tetrimino->shape[row][col], expected_shape[row][col]);
}

Test(tetrimino_create_from_file, not_existing, .init = cr_redirect_stderr)
{
    tetrimino_t *tetrimino = NULL;
    char const tetrimino_path[] = "not_existing at all";

    tetrimino = tetrimino_create_from_file(tetrimino_path);
    cr_assert_null(tetrimino);
}