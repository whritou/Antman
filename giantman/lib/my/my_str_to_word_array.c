/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

char **my_str_to_word_array(char *str)
{
    int line = 0;
    int count = 1;
    for (int j = 0; str[j] != ','; j++)
        if ((str[j] != ' ' && str[j] != '\t') && (str[j + 1] == ' ' ||
        str[j + 1] == '\t' || str[j + 1] == '\0'))
            count++;
    char **tab = malloc(sizeof(char*) * (count + 1));
    for (int i = 0; str[i] != ','; line++) {
        int wordlen = 0;
        for (int j = i; str[j + 1] != '\0' && wordlen == 0 ||
        str[j - 1] != ' ' || str[j] == ' '; ++wordlen, ++j);
        if (wordlen == 0)
            break;
        tab[line] = malloc(sizeof(char) * (wordlen + 1));
        for (int col = 0; col < wordlen; ++col, ++i)
            tab[line][col] = str[i];
        tab[line][wordlen] = '\0';
    }
    tab[line] = NULL;
    return (tab);
}
