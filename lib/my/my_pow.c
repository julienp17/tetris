/*
** EPITECH PROJECT, 2019
** my_compute_power_rec.c
** File description:
** Returns the power of n as recursive function.
*/

int my_pow(int nb, int p)
{
    int res = 1;

    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    res = nb * my_pow(nb, p - 1);
    return (res);
}
