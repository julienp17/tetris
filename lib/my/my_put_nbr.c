/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** Day03
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int div;

    div = 1;
    if (nb == 0)
        my_putchar(48);
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    while (nb / div != 0) {
        div = div * 10;
    }
    div = div / 10;
    while (div > 0) {
        my_putchar(nb / div + 48);
        nb = nb % div;
        div = div / 10;
    }
    return (0);
}
