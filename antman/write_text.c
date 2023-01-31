/*
** EPITECH PROJECT, 2022
** antman
** File description:
** write_text
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

table *write_text_end(data_letter *current, table *tab)
{
    for (int i = 0; i < current->nb_pos; i++) {
        int bitActuel = (current->pos >> (current->nb_pos - (i + 1))) & 1;
        if (tab->nb_bytes != 0)
            tab->octet_fill <<= 1;
        tab->octet_fill |= bitActuel;
        tab->nb_bytes++;
        if (tab->nb_bytes == 8) {
            write(1, &tab->octet_fill,1);
            tab->octet_fill = 0;
            tab->nb_bytes = 0;
        }
    }
    return (tab);
}

table *write_text_next(data_letter *current, table *tab)
{
    if (tab->caractere == current->letter) {
        tab = write_text_end(current, tab);
        current->letter_written = 1;
    }
    return (tab);
}

void write_text(char *str, data_letter *list)
{
    table *tab = malloc(sizeof(table));
    tab->octet_fill = 0;
    tab->nb_bytes = 0;
    int i = 0;
    tab->caractere = str[i];
    while (tab->caractere != '\0') {
        data_letter *current = list;
        while (current) {
            tab = write_text_next(current, tab);
            current = current->next;
        }
        tab->caractere = str[++i];
    }
    if (tab->nb_bytes != 0) {
        tab->octet_fill <<= tab->nb_bytes;
        write(1, &tab->octet_fill, 1);
    }
    free(tab);
}
