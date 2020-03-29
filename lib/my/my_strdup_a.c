/*
** EPITECH PROJECT, 2020
** strdup
** File description:
** trdup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup_a(char * to_copy)
{
    int count = 0;
    char *final;

    while (to_copy[count] != '\0')
        count++;
    final = malloc(sizeof(char) * (count + 1));
    for (int x = 0; x < count; x++)
        final[x] = to_copy[x];
    final[count] = '\0';
    return final;
}
