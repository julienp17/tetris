#include "debug.h"
#include <stdlib.h>
#include <stdio.h>

char left_key(char **str)
{
    debug_t *info = basic_input();

    int i = 0;
    int j = 0;
    int check = 0;

    for (i = 0; str[i] != NULL; i++) {
        if (str[i][j] == '-') {
            check = 1;
            j++;
        }
        if (str[i][j] == 'l' && check == 1)
            check = 2;
        if (check == 2) {
            j += 2;
            info->left_key = str[i][j];
            check = 0;
        }
    }
    return info->left_key;
}

char right_key(char **str)
{
    debug_t *info = basic_input();

    int i = 0;
    int j = 0;
    int check = 0;

    for (i = 0; str[i] != NULL; i++) {
        if (str[i][j] == '-') {
            check = 1;
            j++;
        }
        if (str[i][j] == 'd' && check == 1)
            check = 2;
        if (check == 2) {
            j += 2;
            info->right_key = str[i][j];
            check = 0;
        }
    }
    return info->right_key;
}
