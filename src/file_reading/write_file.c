/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** write_file
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void write_file(char const *file_path, char const *str)
{
    int fd = 0;

    fd = open(file_path, O_WRONLY);
    if (fd < 0) {
        perror(file_path);
        return;
    }
    if (write(fd, str, my_strlen(str)) < 0)
        perror(file_path);
    if (close(fd) < 0)
        perror(file_path);
}