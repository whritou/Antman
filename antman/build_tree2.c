/*
** EPITECH PROJECT, 2022
** antman
** File description:
** compress_text
*/

#include "include/my.h"
#include <stdlib.h>

princ *tree_1(princ *main)
{
    tree *branch = create_node_sum(main->node, main->next->node);
    princ *tmp = create_node_princ(branch);
    tmp->next = main->next->next;
    free(main->next);
    main = tmp;
    return (main);
}

data_letter *tree_2(princ *main, data_letter *current)
{
    if (main->next->node->somme < current->freq) {
        tree *branch = create_node_sum(main->node, main->next->node);
        princ *tmp = create_node_princ(branch);
        tmp->next = main->next->next;
        *main = *tmp;
        free(tmp);
    } else {
        tree *leef = create_node_tree(current);
        tree *branch = create_node_sum(main->node, leef);
        current = current->next;
        princ *tmp = create_node_princ(branch);
        tmp->next = main->next;
        *main = *tmp;
        free(tmp);
    }
    return (current);
}

data_letter *tree_3(princ *main, data_letter *current)
{
    for (; main->next != NULL; main = main->next);
    tree *leef = create_node_tree(current);
    tree *leef2 = create_node_tree(current->next);
    tree *branch = create_node_sum(leef, leef2);
    main->next = create_node_princ(branch);
    current = current->next->next;
    return (current);
}

data_letter *tree_4(princ *main, data_letter *current)
{
    tree *leef = create_node_tree(current);
    tree *branch = create_node_sum(leef, main->node);
    princ *tmp = create_node_princ(branch);
    tmp->next = main->next;
    *main = *tmp;
    free(tmp);
    current = current->next;
    return (current);
}

princ *build_tree(data_letter *current, princ *main)
{
    for (int i = 0; current != NULL || main->next != NULL; i = 0) {
        if (current == NULL) {
            main = tree_1(main);
            ++i;
        }
        if (current != NULL && (main->node->somme < current->freq) && i == 0) {
            current = tree_2(main, current);
            ++i;
        }
        if (current != NULL && (current->next && main->node->somme >
        current->next->freq) && i == 0) {
            current = tree_3(main, current);
            ++i;
        }
        if (i == 0)
            current = tree_4(main, current);
        main = tri_tree(main);
    }
    return (main);
}
