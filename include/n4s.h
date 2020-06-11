/*
** EPITECH PROJECT, 2020
** AIA_n4s_2019
** File description:
** n4s
*/

#ifndef N4S_H_
#define N4S_H_

#include "my.h"

typedef struct info {
    double left;
    double right;
    double mid;
    double speed;
} s_info;

int detect_end(char *str);
void control_speed(s_info *info);
int ia(s_info *info, char **tab);
void my_direction(double value, int neg);
void my_speed(double value);
char *my_gnl(void);

#endif /* !N4S_H_ */
