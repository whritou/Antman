/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** my_printf
*/

#include "../../include/my.h"

int my_printf_state0(char ch, int *count)
{
    if (ch != '%') {
        *count += my_putchar(ch);
        return 0;
    } else
        return 1;
}

int my_printf_state1(const char *format, int *w, struct params *param)
{
    int state = 1;
    if (format[*w] == ' ' || format[*w] == '#'
    || format[*w] == '+' || format[*w] == '-' || format[*w] == '0') {
        int lenght = 0;
        while (param->flag[lenght] != '\0')
            lenght++;
        param->flag[lenght] = format[*w];
        param->flag[lenght + 1] = '\0';
    } else {
        state = 2;
        (*w)--;
    }
    return state;
}

int my_printf_state2(const char *format, int *w, struct params *param)
{
    int state = 2;
    if (format[*w] == '0' || format[*w] == '1' || format[*w] == '2'
        || format[*w] == '3' || format[*w] == '4' || format[*w] == '5'
        || format[*w] == '6' || format[*w] == '7' || format[*w] == '8'
        || format[*w] == '9') {
        int lenght = 0;
        while (param->width[lenght] != '\0')
            lenght++;
        param->width[lenght] = format[*w];
        param->width[lenght + 1] = '\0';
    } else {
        state = 3;
        (*w)--;
    }
    return state;
}

int my_printf2(const char *format, struct params *param, va_list *list)
{
    int count = 0;
    int state = 0;
    int w = 0;
    while (format[w] != '\0' && state != 84) {
        switch (state) {
        case 0:
            state = my_printf_state0(format[w], &count);
            break;
        case 3:
            state = my_printf_put(format[w], list, &count, param);
            param->flag[0] = '\0';
            param->width[0] = '\0';
            break;
        default:
            state = my_printf3(format, param, state, &w);
            break;
        }
        w++;
    }
    return state;
}

int my_printf(const char *format, ...)
{
    va_list list;
    struct params param;
    param.flag[0] = '\0';
    param.width[0] = '\0';
    va_start(list, format);
    int state = my_printf2(format, &param, &list);
    if (state == 84) {
        va_end(list);
        return 84;
    }
    va_end(list);
    return 0;
}
