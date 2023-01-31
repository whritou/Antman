/*
** EPITECH PROJECT, 2022
** antman
** File description:
** main
*/

#include "./include/my.h"

int main(int argc, char **argv)
{
    if (argc != 3)
        return (84);
    if (check_error(argv[1], argc) == 84)
        return (84);
    return (compress_all(argv[1], my_atoi(argv[2])));
}
