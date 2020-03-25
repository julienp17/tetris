/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Returns an allocated game structure
*/

#include <stdlib.h>
#include "game.h"
#include "my.h"

game_t *game_create(uint height, uint width)
{
    game_t *game = NULL;

    game = malloc(sizeof(game_t));
    if (game == NULL) {
        my_puterr("Couldn't allocate memory for game structure.\n");
        return (NULL);
    }
    game->grid = grid_create(height, width);
    if (game->grid == NULL)
        return (NULL);
    game->tetriminos = get_tetriminos_from_dir(TETRIMINOS_DIR_PATH);
    if (game->tetriminos == NULL)
        return (NULL);
    return (game);
}