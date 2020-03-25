/*
** EPITECH PROJECT, 2020
** PSU_tetris_2019
** File description:
** file_reading
*/

#ifndef FILE_READING_H_
    #define FILE_READING_H_

    int get_nb_files_in_dir(char const *pathname);
    unsigned int get_file_size(char const *filepath);
    char *get_file_buffer(char const *filepath);
    char **get_file_lines(char const *pathname);
#endif