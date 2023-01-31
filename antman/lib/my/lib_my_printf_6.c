/*
** EPITECH PROJECT, 2022
** lib_my_printf_6.c
** File description:
** library for my_printf
*/

#include "../../include/my.h"

void my_put_nbr42(char filler, int nb, struct params *param)
{
    if (my_strchr(param->flag, '+') != -1)
        my_putchar('+');
    if (my_strchr(param->flag, ' ') != -1)
        my_putchar(' ');
}

void my_put_nbr4(char filler, int nb, struct params *param)
{
    if (filler != '0') {
        if (nb < 0)
            my_putchar('-');
        else
            my_put_nbr42(filler, nb, param);
    }
}

void my_put_nbr5(int i, char *str)
{
    while (i >= 0) {
        my_putchar(str[i]);
        i--;
    }
}

int my_put_nbr6(int lengt1, int width, char filler, int fulllength)
{
    for (int j = lengt1; j < width; j++) {
        my_putchar(filler);
        fulllength++;
    }
    return fulllength;
}

int my_put_nb22(int nb, int lengt1, struct params *param)
{
    if ((my_strchr(param->flag, '+') != -1)
    || (my_strchr(param->flag, ' ') != -1))
        lengt1++;
    return lengt1;
}
