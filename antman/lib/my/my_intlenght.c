/*
** EPITECH PROJECT, 2022
** lib
** File description:
** my_intlenght
*/

int my_intlenght(int value)
{
    int len = 1;
    for (; 9 < value; len++)
        value /= 10;
    return (len);
}
