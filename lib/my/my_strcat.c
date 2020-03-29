/*
** EPITECH PROJECT, 2020
** my
** File description:
** catstr
*/

#include "my.h"
#include <stdlib.h>

char * my_strcat(char *output, char const *input)
{
    char *tmp = output;
    output = malloc(sizeof(char) * (my_strlen(tmp) + my_strlen(input) + 1));
    int i = 0;

    for (int e = 0; tmp[e] != '\0'; e++, i++)
        output[i] = tmp[e];
    for (int e = 0; input[e] != '\0'; e++, i++)
        output[i] = input[e];
    output[i] = '\0';

    return output;
}
