/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress_image
*/

#include "./include/my.h"

int compress_image(char *str)
{
    char **tab = my_str_to_word_array1(str);
    for (int w = 0; tab[w] != NULL; w++) {
        int g = my_atoi(tab[w]);
        my_printf("%c", g);
    }
    return 0;
}
