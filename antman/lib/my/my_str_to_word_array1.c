/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** lib
*/

#include "../../include/my.h"
#include "stdlib.h"

int get_space_count(const char *str)
{
    int len = my_strlen(str);
    int space_count = 0;
    for (int i = 0; i < len; i++) {
        if ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
            space_count++;
    }
    return space_count;
}

int test(int word_len, char *tmp, char **array, int *space_count)
{
    if (word_len != 0) {
        tmp[word_len++] = '\0';
        array[*space_count] = (char*)malloc(word_len *sizeof(char));
        for (int j = 0; j < word_len; j++)
            array[*space_count][j] = tmp[j];
        (*space_count)++;
        word_len = 0;
    }
    return word_len;
}

char** my_str_to_word_array1(const char *str)
{
    int space_count = get_space_count(str), word_len = 0, len = my_strlen(str);
    char **array = (char**)malloc((space_count + 2)*sizeof(char*));
    char *tmp = (char*)malloc((len + 1)*sizeof(char));
    space_count = 0;
    for (int i = 0; i < len; i++) {
        if ((str[i] != ' ') && (str[i] != '\t') && (str[i] != '\n'))
            tmp[word_len++] = str[i];
        else
            word_len = test(word_len, tmp, array, &space_count);
    }
    tmp[word_len++] = '\0';
    if (word_len > 1) {
        array[space_count] = (char*)malloc(word_len *sizeof(char));
        for (int j = 0; j < word_len; j++)
            array[space_count][j] = tmp[j];
        space_count++;
    }
    array[space_count] = 0;
    free(tmp);
    return array;
}
