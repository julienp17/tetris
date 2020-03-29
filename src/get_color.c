/*
** EPITECH PROJECT, 2020
** getcolor
** File description:
** get the color of the tetriomino
*/

#include "debug.h"
#include <stdlib.h>

int get_color(char *name)
{
    char *size = NULL;
    int i = 0;

    size = get_file_buffer(name);

    for (i = 0; size[i] != '\0'; i++) {
        if (i >= 4) {
            my_putchar(size[i]);
            if (i == 4) {
                my_putchar(' ');
                my_putchar(':');
            }
        }
    }
    return i;
}