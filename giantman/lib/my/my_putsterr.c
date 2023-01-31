/*
** EPITECH PROJECT, 2022
** lib_my_printf_5.c
** File description:
** library for my_printf
*/

#include "../../include/my.h"

int my_putsterr(char const *str)
{
    int lengt = 0;
    while (str[lengt] != '\0') {
        my_puterr(str[lengt]);
        lengt++;
    }
    return (lengt);
}
