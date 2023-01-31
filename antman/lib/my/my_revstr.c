/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_revstr
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_revstr(char *src)
{
    int i = 0;
    int size = my_strlen(src) - 1;
    char *dest = malloc(sizeof(char) * (size + 2));
    for (; src[i] != '\0'; i++)
        dest[i] = src[size--];
    dest[i] = '\0';
    return (dest);
}
