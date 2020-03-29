/*
** EPITECH PROJECT, 2020
** input
** File description:
** this file change the input of the game
*/

#include "debug.h"
#include <stdlib.h>
#include <stdio.h>

char drop_change(char **str)
{
    debug_t *info = basic_input();

    int i = 0;
    int j = 0;
    int check = 0;

    for (i = 0; str[i] != NULL; i++) {
        if (str[i][j] == '-') {
            check = 1;
            j++;
        }
        if (str[i][j] == 'd' && check == 1)
            check = 2;
        if (check == 2) {
            j += 2;
            info->drop = str[i][j];
            check = 0;
        }
    }
    return info->drop;
}

char key_turn_change(char **str)
{
    debug_t *info = basic_input();

    int i = 0;
    int j = 0;
    int check = 0;

    for (i = 0; str[i] != NULL; i++) {
        if (str[i][j] == '-') {
            check = 1;
            j++;
        }
        if (str[i][j] == 't' && check == 1)
            check = 2;
        if (check == 2) {
            j += 2;
            info->key_turn = str[i][j];
            check = 0;
        }
    }
    return info->key_turn;
}

char pause_change(char **str)
{
    debug_t *info = basic_input();

    int i = 0;
    int j = 0;
    int check = 0;

    for (i = 0; str[i] != NULL; i++) {
        if (str[i][j] == '-') {
            check = 1;
            j++;
        }
        if (str[i][j] == 'p' && check == 1)
            check = 2;
        if (check == 2) {
            j += 2;
            info->pause = str[i][j];
            check = 0;
        }
    }
    return info->pause;
}

char quit_change(char **str)
{
    debug_t *info = basic_input();

    int i = 0;
    int j = 0;
    int check = 0;

    for (i = 0; str[i] != NULL; i++) {
        if (str[i][j] == '-') {
            check = 1;
            j++;
        }
        if (str[i][j] == 'q' && check == 1)
            check = 2;
        if (check == 2) {
            j += 2;
            info->quit = str[i][j];
            check = 0;
        }
    }
    return info->quit;
}

debug_t *change_input(char **str)
{
    debug_t *info = NULL;

    info = malloc(sizeof(debug_t));

    info->drop = drop_change(str);
    info->key_turn = key_turn_change(str);
    info->pause = pause_change(str);
    info->quit = quit_change(str);
    info->left_key = left_key(str);
    info->right_key = right_key(str);
    return info;
}