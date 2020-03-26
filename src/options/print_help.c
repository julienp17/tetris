/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Displays the help
*/

#include <stdbool.h>
#include "tetris.h"
#include "my.h"

bool print_help(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "--help") == 0) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" [options]\n");
        my_putstr(USAGE);
        return (true);
    }
    return (false);
}