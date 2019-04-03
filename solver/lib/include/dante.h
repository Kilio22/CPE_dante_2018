/*
** EPITECH PROJECT, 2019
** solver
** File description:
** dante
*/

#pragma once

#define STACK 1048576
#include <stdbool.h>

typedef struct solver_s
{
    bool crossed;
    size_t size[2];
} solver_t;

char **get_map_in_file(char **av);
char **get_map_on_input(void);
char **error_handling(char **map);
int algo(char **map, size_t pos[2], int prev, solver_t **solver);