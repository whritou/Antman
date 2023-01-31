/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress_text
*/

#include "include/my.h"
#include <stdlib.h>

void free_list(data_letter *list)
{
    while (list != NULL) {
        data_letter *tmp = list;
        list = list->next;
        free(tmp);
    }
}

void free_tree(tree *branch)
{
    if (branch->left != NULL)
        free_tree(branch->left);
    if (branch->rigt != NULL)
        free_tree(branch->rigt);
    free(branch);
}

int compress_txt(char *str)
{
    int i = 0;
    char letter = str[0];
    int bytes = 0;
    int deep = 0;
    data_letter* list = add_letter(letter);
    for (int i = 1; (letter = str[i]) != '\0'; ++i)
        letter_already_there(list, letter);
    tri_letter(list);
    tree *tree = init_tree(list);
    if (tree->left != NULL)
        leaf_bytes(tree->left, &bytes, &deep);
    ++bytes;
    if (tree->rigt != NULL)
        leaf_bytes(tree->rigt, &bytes, &deep);
    write_table(str, list);
    write_text(str, list);
    free_list(list);
    free_tree(tree);
    return (0);
}
