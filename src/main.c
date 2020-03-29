/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Main file for tetris
*/

#include <stdlib.h>
#include <time.h>
#include "tetris.h"
#include "debug.h"

int main(int ac, char **av)
{
    if (print_help(ac, av))
        return (0);
    srand(time(NULL));
    tetris();
    return (0);
}