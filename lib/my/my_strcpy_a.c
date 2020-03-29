/*
** EPITECH PROJECT, 2020
** copy
** File description:
** copy
*/

#include <stdlib.h>
#include "my.h"

char *my_strcpy_a(char *str)
{
    int i = 0;
    char *stdest = malloc(sizeof(char) * (my_strlen(str)));

    for (; str[i] != '\0'; i++)
        stdest[i] = str[i];
    stdest[i] = '\0';

    return stdest;
}