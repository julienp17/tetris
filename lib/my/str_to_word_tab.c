/*
** EPITECH PROJECT, 2020
** wordtab
** File description:
** ordtab
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

int nb_word_built(char *buffer)
{
    int i = 0;
    int nb = 1;

    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            nb++;
    }
    return nb;
}

int nb_letters_built(char *buffer)
{
    int i = 0;

    for (; buffer[i] != '\0' && buffer[i] != '\n'; i++);
    return i;
}

char **my_str_to_word_tab(char *buff)
{
    int j = 0;
    int x = 0;
    char **tab = malloc(sizeof(char*) * (nb_word_built(buff) + 1));

    while (*buff) {
        tab[j] = malloc(sizeof(char) * nb_letters_built(buff) + 1);
        x = 0;
        while (*buff && *buff != '\n') {
            tab[j][x] = *buff;
            x++;
            buff++;
        }
        tab[j][x] = '\0';

        if (*buff && *buff == '\n')
            buff++;
        j++;
    }
    tab[j] = NULL;
    return tab;
}