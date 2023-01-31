/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress_text
*/

#include "include/my.h"
#include <stdlib.h>

princ *create_node_princ(tree *node)
{
    princ *new = malloc(sizeof(princ));
    new->node = node;
    new->next = NULL;
    return (new);
}

tree *create_node_tree(data_letter *data)
{
    tree *new = malloc(sizeof(tree));
    new->data = data;
    new->left = NULL;
    new->rigt = NULL;
    new->somme = 0;
    return (new);
}

princ *tri_tree(princ *main)
{
    princ *curr2;
    princ *min;
    tree *tmp;
    for (princ *curr = main; curr->next != NULL; curr = curr->next) {
        min = curr->next;
        curr2 = curr->next->next;
        for (; curr2 != NULL; curr2 = curr2->next)
            (curr2->node->somme < min->node->somme) ? min = curr2 : 0;
        if (curr->node->somme > min->node->somme) {
            tmp = min->node;
            min->node = curr->node;
            curr->node = tmp;
        }
    }
    return (main);
}

tree *create_node_sum(tree *left, tree *right)
{
    tree *node = malloc(sizeof(tree));
    int i = 0;
    node->left = left;
    node->rigt = right;
    if (left->somme == 0 && right->somme == 0) {
        node->somme = left->data->freq + right->data->freq;
        ++i;
    }
    if (left->somme == 0 && i == 0) {
        node->somme = left->data->freq + right->somme;
        ++i;
    }
    if (right->somme == 0 && i == 0) {
        node->somme = left->somme + right->data->freq;
        ++i;
    }
    if (i == 0)
        node->somme = left->somme + right->somme;
    return (node);
}

tree *init_tree(data_letter *data)
{
    tree *leaf = create_node_tree(data);
    if (data->next == NULL)
        return (leaf);
    tree *leaf_2 = create_node_tree(data->next);
    tree *branch = create_node_sum(leaf, leaf_2);
    princ *main = create_node_princ(branch);
    data_letter *current = data->next->next;
    main = build_tree(current, main);
    return (main->node);
}
