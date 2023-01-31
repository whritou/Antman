/*
** EPITECH PROJECT, 2022
** lib_my_printf_4.c
** File description:
** library for my_printf
*/

#include "../../include/my.h"

char my_get_x(int caps)
{
    if (caps)
        return 'X';
    else
        return 'x';
}

int my_get_dieze(struct params *param, int base, char *dieze, int caps)
{
    int fulllength = 0;
    if (my_strchr(param->flag, '#') != -1) {
        switch (base) {
        case 16:
            dieze[0] = '0';
            dieze[1] = my_get_x(caps);
            dieze[2] = '\0';
            fulllength += 2;
            break;
        case 8:
            dieze[0] = '0';
            dieze[1] = '\0';
            fulllength++;
            break;
        default:
            break;
        }
    }
    return fulllength;
}

int my_put_noinf_filler(int length, int width, char filler, int fulllength)
{
    for (int j = length; j < width; j++) {
        my_putchar(filler);
        fulllength++;
    }
    return fulllength;
}

int my_get_noinf_main(char *str, int base, int caps, struct params *param)
{
    int length = 0;
    int fulllength = 0;
    char dieze[16] = "";
    char filler = ' ';
    while (str[length] != '\0')
        length++;
    fulllength += length;
    fulllength += my_get_dieze(param, base, dieze, caps);
    int width = my_atoi(param->width);
    if (my_strchr(param->flag, '0') != -1)
        filler = '0';
    if (my_strchr(param->flag, '-') == -1)
        fulllength = my_put_noinf_filler(length, width, filler, fulllength);
    my_putstr(dieze);
    my_putstr(str);
    if (my_strchr(param->flag, '-') != -1)
        fulllength = my_put_noinf_filler(length, width, filler, fulllength);
    return fulllength;
}

int my_get_noinfzero2(va_list *list, int base, int caps, struct params *param)
{
    char str[256] = "";
    int val = (int)va_arg(*list, int);
    if (val < 0) {
        return -1;
    } else {
        my_itoa(val, str, base, caps);
        return my_get_noinf_main(str, base, caps, param);
    }
}
