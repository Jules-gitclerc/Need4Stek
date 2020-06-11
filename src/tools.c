/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** exec_command
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "n4s.h"

char *my_gnl(void)
{
    char *buff = NULL;
    size_t size;

    if (getline(&buff, &size, stdin) == -1)
        return (NULL);
    return (buff);
}

int detect_end(char *str)
{
    if (strcmp(str, "Track Cleared") == 0) {
        write(1, "STOP SIMULATION\n", strlen("STOP SIMULATION\n"));
        return (1);
    }
    return (0);
}

void my_direction(double value, int nb)
{
    char *buff = NULL;

    write(1, "WHEELS_DIR:", strlen("WHEELS_DIR:"));
    if (nb == 1)
        dprintf(1, "-");
    dprintf(1, "%.2f\n", value);
    buff = my_gnl();
    if (detect_end(buff) == 1) {
        free(buff);
        exit(0);
    }
    free(buff);
}

void my_speed(double value)
{
    char *buff = NULL;

    write(1, "CAR_FORWARD:", strlen("CAR_FORWARD:"));
    dprintf(1, "%.2f\n", value);
    buff = my_gnl();
    if (detect_end(buff) == 1) {
        free(buff);
        exit(0);
    }
    free(buff);
}
