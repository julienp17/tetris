/*
** EPITECH PROJECT, 2020
** putstr
** File description:
** but multiple string
*/

void my_putstr_m(char *what, char *name, char *size, char *color)
{
    int i = 0;

    for (i = 0; what[i] != '\0'; i++)
        my_putchar(what[i]);

    for (i = 0; name[i] != '\0'; i++)
        my_putchar(name[i]);

    for (i = 0; size[i] != '\0'; i++)
        my_putchar(size[i]);

    for (i = 0; color[i] != '\0'; i++)
        my_putchar(color[i]);
}