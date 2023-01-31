/*
** EPITECH PROJECT, 2022
** lib_my_printf.c
** File description:
** library for my_printf
*/

#include "../../include/my.h"

int my_put_nbr_str(int nb, char *str)
{
    if (nb < 0) {
        nb *= -1;
    }
    int i = 0;
    if (nb == 0) {
        str[i] = '0';
        i++;
    } else {
        while (nb != 0) {
            str[i] = (nb % 10) + '0';
            nb /= 10;
            i++;
        }
    }
    str[i] = '\0';
    return i;
}

int my_put_nbr2(int nb, int lengt1, struct params *param)
{
    if (nb < 0)
        lengt1++;
    else
        lengt1 = my_put_nb22(nb, lengt1, param);
    return lengt1;
}

char my_put_nbr3(int nb, char filler, struct params *param)
{
    if (my_strchr(param->flag, '0') != -1)
        filler = '0';
    if (filler == '0') {
        if (nb < 0)
            my_putchar('-');
        else
            my_put_nbr42(filler, nb, param);
    }
    return filler;
}

int my_put_nbr(int nb, struct params *param)
{
    char str[16] = "";
    int i = my_put_nbr_str(nb, str);
    int lengt1 = my_put_nbr2(nb, i, param);
    int fulllength = lengt1;
    char filler = my_put_nbr3(nb, ' ', param);
    int width = my_atoi(param->width);
    if (my_strchr(param->flag, '-') == -1) {
        fulllength = my_put_nbr6(lengt1, width, filler, fulllength);
    }
    my_put_nbr4(filler, nb, param);
    my_put_nbr5(i, str);
    if (my_strchr(param->flag, '-') != -1) {
        fulllength = my_put_nbr6(lengt1, width, filler, fulllength);
    }
    return fulllength;
}
