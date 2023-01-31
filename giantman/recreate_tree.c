/*
** EPITECH PROJECT, 2022
** giaantman
** File description:
** recreate_tree
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

table *init_tab(table *tab, char *dico)
{
    tab->tot_letter = my_strlen(dico);
    tab->currpos_letter = 1;
    tab->curent_letter = dico[0];
    tab->letter = tab->curent_letter;
    tab->bytes = 0;
    tab->byte_pos = 0;
    tab->ignore = 0;
    return (tab);
}

table *recreate_tree_end(table *tab, int *empty_bytes, char *dico)
{
    tab->letter = tab->curent_letter;
    tab->bytes = 0;
    tab->byte_pos = 0;
    while (tab->curent_letter != ',' || tab->ignore) {
        tab->currpos_letter++;
        tab->curent_letter = dico[tab->i++];
        if (tab->curent_letter != ',') {
            tab->bytes |= tab->curent_letter - 48;
            tab->bytes <<= 1;
            tab->byte_pos++;
        }
        if (tab->ignore)
            tab->ignore = 0;
    }
    tab->ignore = 1;
    return (tab);
}

data *recreate_tree_next(table *tab, char *dico, int *empty_bytes)
{
    tab->bytes >>= 1;
    data *liste = create_data_node(tab->letter, tab->bytes, tab->byte_pos);
    data *actuel = liste;
    tab->currpos_letter++;
    tab->curent_letter = dico[tab->i++];
    while (tab->curent_letter != '\0') {
        tab = recreate_tree_end(tab, empty_bytes, dico);
        tab->bytes >>= 1;
        data *node = create_data_node(tab->letter, tab->bytes, tab->byte_pos);
        actuel->next = node;
        actuel = actuel->next;
        ++tab->currpos_letter;
        tab->curent_letter = dico[tab->i++];
    }
    return (liste);
}

data *recreate_tree(char *dico, int *empty_bytes)
{
    table *tab = malloc(sizeof(table));
    tab = init_tab(tab, dico);
    tab->i = 0;
    while (tab->curent_letter != ',') {
        tab->currpos_letter++;
        tab->curent_letter = dico[++tab->i];
        if (tab->curent_letter != ',') {
            tab->bytes |= tab->curent_letter - 48;
            tab->bytes <<= 1;
            tab->byte_pos++;
        }
    }
    data *list = recreate_tree_next(tab, dico, empty_bytes);
    free(tab);
    return (list);
}

data *tri_tree(data *list)
{
    for (data *look = list; look->next != NULL; look = look->next) {
        data *min = look->next;
        for (data *look2 = look->next->next; look2; look2 = look2->next)
            (look2->nb_pos < min->nb_pos) ? min = look2 : 0;
        if (min->nb_pos < look->nb_pos) {
            char tmp_letter = look->letter;
            char tmp_pos = look->pos;
            char tmp_nb_pos = look->nb_pos;
            look->letter = min->letter;
            look->pos = min->pos;
            look->nb_pos = min->nb_pos;
            min->letter = tmp_letter;
            min->pos = tmp_pos;
            min->nb_pos = tmp_nb_pos;
        }
    }
    return (list);
}
