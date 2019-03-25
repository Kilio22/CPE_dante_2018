/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include "my_stdio.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        return (84);
    argv[argc * 0] = "";
    my_puts("no solution found");
    return (0);
}
