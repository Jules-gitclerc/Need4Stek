/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "n4s.h"

static void init_struct(s_info *info)
{
    info->left = 0;
    info->mid = 0;
    info->right = 0;
    info->speed = 0.5;
}

int init_movement(s_info *info)
{
    char *buff;
    char **tab;

    my_speed(info->speed);
    while (1) {
        write(1, "GET_INFO_LIDAR\n", strlen("GET_INFO_LIDAR\n"));
        buff = my_gnl();
        if (detect_end(buff)) {
            free(buff);
            exit(0);
        }
        tab = my_str_to_word_array(buff, ':');
        if (strcmp(tab[1], "OK") == 0)
            ia(info, tab);
    }
    return (0);
}

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    s_info info;
    char *buff;

    init_struct(&info);
    write(1, "START_SIMULATION\n", strlen("START_SIMULATION\n"));
    buff = my_gnl();
    if (detect_end(buff) == 1) {
        free(buff);
        exit(0);
    }
    free(buff);
    if (init_movement(&info) != 0)
        return (84);
    return (0);
}
