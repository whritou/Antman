/*
** EPITECH PROJECT, 2022
** antman
** File description:
** structure
*/

#include "./include/my.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int structure(char *str, int type)
{
    if (type == 1)
        decompress_txt(str) ;
    if (type == 2)
        decompress_txt(str);
    if (type == 3)
        return (0);
    if (type != 1 && type != 2 && type != 3)
        return (84);
    return (0);
}

int read_all(char *path, int type)
{
    int folder = 0;
    int size = 1;
    if (open(path, O_RDONLY) == -1)
        return (84);
    struct stat *st = malloc(sizeof(struct stat));
    stat(path, st);
    char *buffer = malloc(sizeof(char) * st->st_size + 1);
    folder = open(path, O_RDONLY);
    size = read(folder, buffer, st->st_size);
    buffer[size++] = '\0';
    free(st);
    structure(buffer, type);
    free(buffer);
    return (0);
}
