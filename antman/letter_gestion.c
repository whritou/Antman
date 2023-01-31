/*
** EPITECH PROJECT, 2022
** antman
** File description:
** letter_gestion
*/

#include "include/my.h"
#include <stdlib.h>

data_letter *add_letter(char letter)
{
    data_letter *node = malloc(sizeof(data_letter));
    node->letter = letter;
    node->freq = 1;
    node->letter_written = 0;
    node->next = NULL;
    return (node);
}

void letter_already_there(data_letter *list, char letter)
{
    for (; list->next != NULL && list->letter != letter; list = list->next);
    if (list->next == NULL)
        list->next = add_letter(letter);
    else
        list->freq++;
}

void tri_letter(data_letter *list)
{
    data_letter *less = list;
    char letter;
    int freq;
    for (data_letter *look = list; list->next != NULL; look = list->next) {
        for (; look != NULL; look = look->next)
            (look->freq < less->freq) ? less = look : 0;
        letter = less->letter;
        freq = less->freq;
        less->letter = list->letter;
        less->freq = list->freq;
        list->letter = letter;
        list->freq = freq;
        list = list->next;
        less = list;
    }
}

void leaf_bytes(tree *tree, int *bytes, int *deep)
{
    ++(*deep);
    if (tree->somme != 0) {
        (*bytes) <<= 1;
        if (tree->left)
            leaf_bytes(tree->left, bytes, deep);
        if (tree->rigt) {
            (*bytes) |= 1;
            leaf_bytes(tree->rigt, bytes, deep);
        }
        (*bytes) >>= 1;
    } else {
        tree->data->pos = *bytes;
        tree->data->nb_pos = *deep;
    }
    --(*deep);
}
