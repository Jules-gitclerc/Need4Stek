/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** ia
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "string.h"
#include "n4s.h"
#include "my.h"

void set_info(s_info *info, char **tab)
{
    info->left = atof(tab[3]);
    info->mid = atof(tab[19]);
    info->right = atof(tab[34]);
}

void right_or_left(s_info *info, int nb)
{
    double direction[6] = {0.33, 0.3, 0.22, 0.18, 0.03, 0.01};
    int range[5] = {400, 500, 700, 1020, 1350};
    int i = 0;

    while (i <= 4) {
        if (info->mid < range[i]) {
            nb == 1 ?
            my_direction(direction[i], 1) : my_direction(direction[i], 0);
            break;
        } else
            i++;
    }
    if (i == 5)
        nb == 1 ?
        my_direction(direction[i], 1) : my_direction(direction[i], 0);
}

int ia(s_info *info, char **tab)
{
	set_info(info, tab);
    (info->left > info->right) ?
        right_or_left(info, 0) : right_or_left(info, 1);
    if (detect_end(tab[35]) == 1)
        exit(0);
    return (0);
}

void control_speed(s_info *info)
{
    double speed[8] = {1.0, 0.79, 0.62, 0.5, 0.39, 0.27, 0.2, 0.1};
    int mid[7] = {2500, 2000, 1500, 1000, 500, 400, 300};
    int i = 0;

    while (i <= 6) {
        if (info->mid > mid[i]) {
            my_speed(speed[i]);
            break;
        } else
            i++;
    }
    if (i == 7)
        my_speed(speed[i]);
}
