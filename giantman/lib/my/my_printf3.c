/*
** EPITECH PROJECT, 2022
** my_printf3.c
** File description:
** my_printf3.c
*/

#include "../../include/my.h"

int my_printf_put6(char ch, va_list *list, int *count, struct params *param)
{
    switch (ch) {
    case 'm':
        my_putstr("System error");
        break;
    default:
        return 84;
    }
    return (0);
}

int my_printf3(const char *format, struct params *param, int state, int *w)
{
    switch (state) {
    case 1:
        state = my_printf_state1(format, w, param);
        break;
    case 2:
        state = my_printf_state2(format, w, param);
        break;
    default:
        state = 1;
        break;
    }
    return state;
}
