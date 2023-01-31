/*
** EPITECH PROJECT, 2022
** lib_my_printf_2.c
** File description:
** library for my_printf
*/

#include "../../include/my.h"

char hexa_min(int nb)
{
    switch (nb) {
    case 10:
        return 'a';
    case 11:
        return 'b';
    case 12:
        return 'c';
    case 13:
        return 'd';
    case 14:
        return 'e';
    case 15:
        return 'f';
    default:
        return nb + '0';
    }
}

char hexa_maj(int nb)
{
    switch (nb) {
    case 10:
        return 'A';
    case 11:
        return 'B';
    case 12:
        return 'C';
    case 13:
        return 'D';
    case 14:
        return 'E';
    case 15:
        return 'F';
    default:
        return nb + '0';
    }
}

int my_itoa_count(int nb, int base)
{
    int count = 1;
    int num = nb;
    if (nb < 0) {
        count++;
        num = -nb;
    }
    while (num / base != 0) {
        num = num / base;
        count++;
    }
    return count;
}

void my_itoa_minus(int nb, char *str)
{
    if (nb < 0)
        str[0] = '-';
}

char *my_itoa(int nb, char *str, int base, int caps)
{
    int count = my_itoa_count(nb, base);
    int num = nb;
    if (nb < 0)
        num = -nb;
    str[count] = '\0';
    count--;
    while (num / base != 0) {
        if (caps)
            str[count] = hexa_maj(num % base);
        else
            str[count] = hexa_min(num % base);
        num = num / base;
        count--;
    }
    if (caps)
        str[count] = hexa_maj(num % base);
    else
        str[count] = hexa_min(num % base);
    my_itoa_minus(nb, str);
    return str;
}
