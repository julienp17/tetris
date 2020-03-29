/*
** EPITECH PROJECT, 2020
** my
** File description:
** strncmp
*/

int my_strncmp(char const *s1, char const *s2)
{
        int i = 0;

        for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
        return (s1[i] - s2[i]);
}