/*
** EPITECH PROJECT, 2022
** my_printf_2.c
** File description:
** my_printf addon
*/

#include "../../include/my.h"

int my_printf_put5(char ch, va_list *list, int *count, struct params *param)
{
    int ret = 0;
    char str[256] = "";
    int *ptr = 0;
    switch (ch) {
    case 'n':
        ptr = (int*)va_arg(*list, int*);
        *ptr = *count;
        break;
    case 'S':
        my_putstroctal((char*)va_arg(*list, char*));
        break;
    case 'p':
        if (my_get_noinfzero1(list, 16, 0) == 84)
            return 84;
        else
            break;
    default:
        return my_printf_put6(ch, list, count, param);
    }
    return 0;
}

int my_printf_put4(char ch, va_list *list, int *count, struct params *param)
{
    int ret = 0;
    char str[256] = "";
    int *ptr = 0;
    switch (ch) {
    case 'x':
        if (my_get_noinfzero2(list, 16, 0, param) == 84)
            return 84;
        else
            break;
    case 'X':
        if (my_get_noinfzero2(list, 16, 1, param) == 84)
            return 84;
        else
            break;
    default:
        return my_printf_put5(ch, list, count, param);
    }
    return 0;
}

int my_printf_put3(char ch, va_list *list, int *count, struct params *param)
{
    int ret = 0;
    char str[256] = "";
    int *ptr = 0;
    switch (ch) {
    case 'u':
        if (my_get_noinfzero2(list, 10, 0, param) == 84)
            return 84;
        else
            break;
    case 'b':
        if (my_get_noinfzero2(list, 2, 0, param) == 84)
            return 84;
        else
            break;
    default:
        return my_printf_put4(ch, list, count, param);
    }
    return 0;
}

int my_printf_put2(char ch, va_list *list, int *count, struct params *param)
{
    int ret = 0;
    char str[256] = "";
    int *ptr = 0;
    switch (ch) {
    case '%':
        *count += my_putchar('%');
        break;
    case 'o':
        ret = my_get_noinfzero2(list, 8, 0, param);
        if (ret == -1)
            return 84;
        else {
            *count += ret;
            break;
        }
    default:
        return my_printf_put3(ch, list, count, param);
    }
    return 0;
}

int my_printf_put(char ch, va_list *list, int *count, struct params *param)
{
    int ret = 0;
    char str[256] = "";
    int *ptr = 0;
    int number = 0;
    switch (ch) {
    case 'c':
        *count += my_putchar((char)va_arg(*list, int));
        break;
    case 's':
        *count += my_putstr((char*)va_arg(*list, char*));
        break;
    case 'i':
    case 'd':
        number = (int)va_arg(*list, int);
        *count += my_put_nbr(number, param);
        break;
    default:
        return my_printf_put2(ch, list, count, param);
    }
    return 0;
}
