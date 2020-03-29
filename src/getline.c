/*
** EPITECH PROJECT, 2020
** getline
** File description:
** tetris
*/

#include "debug.h"
#include <stdlib.h>
#include <stdio.h>

char *prompt_command(void)
{
    char *line = NULL;
    size_t size;

    getline(&line, &size, stdin);

    return line;
}