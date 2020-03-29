/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** test_tetrimino_create
*/

#include <criterion/criterion.h>
#include "tetrimino.h"

Test(tetrimino_create, basic_usage)
{
    tetrimino_t *tetrimino = NULL;

    tetrimino = tetrimino_create();
    cr_assert_not_null(tetrimino);
    cr_assert_null(tetrimino->name);
    cr_assert_null(tetrimino->shape);
    cr_assert_eq(tetrimino->color, 0);
    cr_assert_eq(tetrimino->size.x, 0);
    cr_assert_eq(tetrimino->size.y, 0);
    cr_assert_eq(tetrimino->square_size, 0);
}