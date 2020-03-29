/*
** EPITECH PROJECT, 2020
** debug structure
** File description:
** initialisation
*/

#include "debug.h"
#include <stdlib.h>

debug_t *basic_input(void)
{
    debug_t *info = NULL;

    info = malloc(sizeof(debug_t));

    info->drop = "x";
    info->key_turn = "(space)";
    info->pause = "p";
    info->quit = "q";

    return info;
}