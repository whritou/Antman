/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    while (dest[i])
        i++;
    dest[i] = src[0];
    for (int j = 0; src[j]; j++, i++)
        dest[i] = src[j];
    dest[i] = '\0';
    return (dest);
}
