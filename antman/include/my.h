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

typedef struct data_letter_t {
    char letter;
    int freq;
    int pos;
    int nb_pos;
    int letter_written;
    struct data_letter_t *next;
} data_letter;

typedef struct tree_t {
    data_letter *data;
    struct tree_t *left;
    struct tree_t *rigt;
    int somme;
} tree;

typedef struct princ_t {
    struct tree_t *node;
    struct princ_t *next;
} princ;

typedef struct table_t {
    int octet_fill;
    long nb_bytes;
    char caractere;
} table;


tree *init_tree(data_letter *node);
princ *build_tree(data_letter *current, princ *main);
princ *tri_tree(princ *main);
princ *create_node_princ(tree *node);
tree *create_node_tree(data_letter *data);
tree *create_node_sum(tree *left, tree *right);
data_letter *add_letter(char letter);
void letter_already_there(data_letter *list, char letter);
void tri_letter(data_letter *list);
void leaf_bytes(tree *tree, int *bytes, int *deep);
void write_text(char *str, data_letter *list);
void write_table(char *str, data_letter *list);


char *my_strcat(char *dest, char const *src);
int my_strlen(char const *str);
int my_intlenght(int value);
char **my_str_to_word_array(char *str);
char** my_str_to_word_array1(const char *str);
char *my_revstr(char *src);
char *my_int_to_str(int nb);
void free_all(char **tab);
int compress_all(char *path, int type);
int check_error(char *path, int argc);
int compress_image(char *str);
int compress_txt(char *str);
