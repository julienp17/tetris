/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** Swaps two int
*/

void my_swap_int(int *nb1, int *nb2)
{
    int tmp = 0;

    tmp = *nb1;
    *nb1 = *nb2;
    *nb2 = tmp;
}