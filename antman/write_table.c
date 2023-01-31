/*
** EPITECH PROJECT, 2022
** antman
** File description:
** write_table
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>

table *write_table_end(data_letter *current, table *tab)
{
    int virg = ',';
    for (int i = 0; i < current->nb_pos; i++) {
        int bitActuel = (current->pos >> (current->nb_pos - (i + 1))) & 1;
        if (tab->nb_bytes != 0)
            tab->octet_fill <<= 1;
        tab->octet_fill |= bitActuel;
        tab->nb_bytes++;
        if (tab->nb_bytes == 8) {
            tab->octet_fill = 0;
            tab->nb_bytes = 0;
        }
        if (!current->letter_written) {
            int nb_bit = bitActuel + 48;
            write(1, &nb_bit, 1);
        }
    }
    if (!current->letter_written)
        write(1, &virg, 1);
    return (tab);
}

table *write_table_next(data_letter *current, table *tab)
{
    if (tab->caractere == current->letter) {
        if (!current->letter_written)
            write(1, &current->letter, 1);
        tab = write_table_end(current, tab);
        current->letter_written = 1;
    }
    return (tab);
}

void write_table(char *str, data_letter *list)
{
    table *tab = malloc(sizeof(table));
    tab->octet_fill = 0;
    tab->nb_bytes = 0;
    int end = '@';
    tab->caractere = str[0];
    for (int i = 0; tab->caractere != '\0';) {
        data_letter *current = list;
        while (current) {
            tab = write_table_next(current, tab);
            current = current->next;
        }
        tab->caractere = str[++i];
    }
    if (tab->nb_bytes != 0) {
        int nbBitsVides = 8 - tab->nb_bytes + 48;
        write(1, &nbBitsVides, 1);
    }
    write(1, &end, 1);
    free(tab);
}
