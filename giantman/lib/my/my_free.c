/*
** EPITECH PROJECT, 2022
** my_free
** File description:
** free all in a **
*/

#include <stdlib.h>

void free_all(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
