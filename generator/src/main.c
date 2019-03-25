/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "my_stdio.h"

int main(int argc, char *argv[])
{
    int x;
    int y;

    if (argc < 3)
        return (84);
    if (!my_str_isnum(argv[1], 0) || !my_str_isnum(argv[2], 0))
        return (84);
    x = atoi(argv[1]);
    y = atoi(argv[2]);
    if (!x || !y)
        return (84);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            my_putchar('*');
        my_putchar('\n');
    }
    return (0);
}
