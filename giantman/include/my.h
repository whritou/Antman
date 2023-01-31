/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** include for library for my_printf
*/

#include <stdarg.h>
#include <unistd.h>

#pragma once

struct params {
    char flag[256];
    char width[256];
};

int my_putsterr(char const *str);
int my_puterr(char c);
int my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb, struct params *param);
char *my_itoa(int nb, char *str, int base, int caps);
int my_get_noinfzero1(va_list *list, int base, int caps);
char *my_ptoa(unsigned long long nb, char *str, int base, int caps);
int my_get_noinfzero2(va_list *list, int base, int caps, struct params *param);
int my_putstroctal(char const *str);
int my_atoi(char *str);
int my_printf(const char *format, ...);
int my_printf_put6(char ch, va_list *list, int *count, struct params *param);
int my_printf_put(char ch, va_list *list, int *count, struct params *param);
int my_printf3(const char *format, struct params *param, int state, int *w);
int my_printf_state1(const char *format, int *w, struct params *param);
int my_printf_state2(const char *format, int *w, struct params *param);
int my_strchr(char *str, char c);
char hexa_min(int nb);
char hexa_maj(int nb);
void my_put_nbr4(char filler, int nb, struct params *param);
void my_put_nbr5(int i, char *str);
int my_put_nbr6(int lengt1, int width, char filler, int fulllength);
int my_put_nb22(int nb, int lengt1, struct params *param);
void my_put_nbr42(char filler, int nb, struct params *param);
int my_strlen(char *str);

int read_all(char *path, int type);
void decompress_txt(char *str);
void free_all(char **tab);

typedef struct data_t {
    char letter;
    int pos;
    int nb_pos;
    struct data_t *next;
} data;

typedef struct table_t {
    int tot_letter;
    int currpos_letter;
    char curent_letter;
    char letter;
    int bytes;
    int byte_pos;
    int i;
    int ignore;
} table;

data *create_data_node(char letter, int pos, int nb_pos);
data *tri_tree(data *list);
data *recreate_tree(char *dico, int *empty_bytes);
