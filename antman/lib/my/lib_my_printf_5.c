/*
** EPITECH PROJECT, 2022
** lib_my_printf_5.c
** File description:
** library for my_printf
*/

#include "../../include/my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}

int my_putstr(char const *str)
{
    int lengt = 0;
    while (str[lengt] != '\0') {
        my_putchar(str[lengt]);
        lengt++;
    }
    return (lengt);
}

int my_putstroctal_write(int count, char const *str, int lengt)
{
    char tmp[16];
    my_putchar('\\');
    count++;
    my_itoa((unsigned char)str[lengt], tmp, 8, 0);
    int len = 0;
    while (tmp[len] != '\0')
        len++;
    for (int i = len; i < 3 ; i++) {
        my_putchar('0');
        count++;
    }
    my_putstr(tmp);
    count += len;
    return count;
}

int my_putstroctal(char const *str)
{
    int count = 0;
    int lengt = 0;
    while (str[lengt] != '\0') {
        if (str[lengt] < 32 || str[lengt] >= 127)
            count = my_putstroctal_write(count, str, lengt);
        else {
            my_putchar(str[lengt]);
            count++;
        }
        lengt++;
    }
    return (count);
}

int my_strchr(char *str, char c)
{
    int lengt = 0;
    while (str[lengt] != '\0') {
        if (str[lengt] == c)
            return lengt;
        lengt++;
    }
    return -1;
}
