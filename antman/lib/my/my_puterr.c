/*
** EPITECH PROJECT, 2022
** my_ls
** File description:
** ls
*/

#include "../../include/my.h"

int my_puterr(char c)
{
    write(2, &c, 1);
    return 1;
}
