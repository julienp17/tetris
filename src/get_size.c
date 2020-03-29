/*
** EPITECH PROJECT, 2020
** getsize
** File description:
** get the tetriomino size
*/

#include "debug.h"
#include <stdlib.h>

int get_size(char *name)
{
    char *size = NULL;
    int i = 0;

    size = get_file_buffer(name);

    for (i = 0; i != 3; i++) {
        if (i == 2)
            my_putstr("*");
        if (size[i] != ' ')
            my_putchar(size[i]);
    }
    return i;
}