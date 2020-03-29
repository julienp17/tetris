/*
** EPITECH PROJECT, 2020
** get_file
** File description:
** name
*/

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include "debug.h"
#include <stdlib.h>

char *get_file_name(DIR *file)
{
    struct dirent* f_read = NULL;
    file = opendir("./tetriminos");
    if (file == NULL)
        exit(1);

    f_read = readdir(file);

     if (closedir(file) == -1)
        exit(-1);

    return f_read->d_name;
}