/*
** EPITECH PROJECT, 2022
** lib_my_printf_3.c
** File description:
** library for my_printf
*/

#include "../../include/my.h"

int my_ptoa_count(unsigned long long nb, int base)
{
    int count = 1;
    unsigned long long num = nb;
    if (nb < 0) {
        count++;
        num = -nb;
    }
    while (num / base != 0) {
        num = num / base;
        count++;
    }
    count += 2;
    return count;
}

void my_ptoa_minus(int count, unsigned long long nb, char *str)
{
    count--;
    str[count] = 'x';
    count--;
    str[count] = '0';
    if (nb < 0)
        str[0] = '-';
}

char *my_ptoa(unsigned long long nb, char *str, int base, int caps)
{
    int count = my_ptoa_count(nb, base);
    unsigned long long num = nb;
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
    my_ptoa_minus(count, nb, str);
    return str;
}

int my_get_noinfzero1(va_list *list, int base, int caps)
{
    char str[256] = "";
    unsigned long long val = (unsigned long long)va_arg(*list, char*);
    if (val < 0) {
        return -1;
    } else {
        return my_putstr(my_ptoa(val, str, base, caps));
    }
}

int my_atoi(char *str)
{
    int ret = 0;
    int lenght = 0;
    while (str[lenght] != '\0')
        lenght++;
    lenght--;
    int count = 0;
    while (lenght >= 0) {
        int val = str[lenght] - '0';
        for (int i = 0; i < count; i++) {
            val *= 10;
        }
        ret += val;
        lenght--;
        count++;
    }
    return ret;
}
