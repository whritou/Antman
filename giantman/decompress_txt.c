/*
** EPITECH PROJECT, 2022
** giaantman
** File description:
** decompress_txt
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

data *create_data_node(char letter, int pos, int nb_pos)
{
    data* node = malloc(sizeof(data));
    node->letter = letter;
    node->pos = pos;
    node->nb_pos = nb_pos;
    node->next = NULL;
    return (node);
}

void print_tree_next(int *byte, int *nb_gbytes, data *list)
{
    for (; list != NULL; list = list->next) {
        if (*nb_gbytes == list->nb_pos && *byte == list->pos) {
            write(1, &list->letter, 1);
            (*byte) = 0;
            (*nb_gbytes) = 0;
        }
    }
}

void print_tree(char *compress_data, data *list)
{
    int j = 0;
    char letter = compress_data[j];
    int byte = 0;
    int nb_bytes = 0;
    for (int current_nb = 0; letter != '\0'; current_nb++) {
        for (int i = 0; i < 8; i++) {
            byte |= (letter >> (8 - (i + 1))) & 1;
            nb_bytes++;
            print_tree_next(&byte, &nb_bytes, list);
            byte <<= 1;
        }
        letter = compress_data[j++];
    }
}

void free_list(data *list)
{
    while (list != NULL) {
        data *tmp = list;
        list = list->next;
        free(tmp);
    }
}

void decompress_txt(char *str)
{
    int i;
    int j;
    int g = 0;
    int empty_bytes = 0;
    for (i = 0; str[i] != '@'; i++);
    char *dico = malloc(sizeof(char) * (i + 3));
    for (i = 0; str[i] != '@'; i++)
        dico[i] = str[i];
    dico[i++] = '\0';
    for (j = i; str[j] != '\0'; j++);
    char *compress_data = malloc(sizeof(char) * (j + 2));
    for (; str[i] != '\0'; i++, g++)
        compress_data[g] = str[i];
    compress_data[g++] = '\0';
    data *list = recreate_tree(dico, &empty_bytes);
    list = tri_tree(list);
    print_tree(compress_data, list);
    free_list(list);
    free(dico);
    free(compress_data);
}
