/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** Returns the number of files in a directory
*/

#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include "my.h"

int get_nb_files_in_dir(char const *pathname)
{
    DIR *dir = NULL;
    char *file_name = NULL;
    struct dirent *dir_entry = NULL;
    int nb_files = 0;

    if ((dir = opendir(pathname)) == NULL) {
        perror(pathname);
        return (-1);
    }
    while ((dir_entry = readdir(dir)) != NULL) {
        file_name = dir_entry->d_name;
        if (my_strcmp(file_name, ".") != 0 && my_strcmp(file_name, "..") != 0)
            nb_files++;
    }
    if (closedir(dir) != 0) {
        perror(pathname);
        return (-1);
    }
    return (nb_files);
}