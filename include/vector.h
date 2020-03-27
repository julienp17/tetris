/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** vector
*/

#ifndef VECTOR_H_
    #define VECTOR_H_

    typedef struct vector {
        int x;
        int y;
    } vec_t;

    #define vec(x, y)           ((vec_t) {(x), (y)})
#endif