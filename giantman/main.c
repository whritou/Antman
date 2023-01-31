/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** lib
*/
#include "./include/my.h"

int main(int argc, char **argv)
{
    if (argc != 3)
        return (84);
    read_all(argv[1], my_atoi(argv[2]));
}
