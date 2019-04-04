/*
** EPITECH PROJECT, 2019
** solver
** File description:
** dante
*/

#pragma once

#define STACK 1048576
#include <stdbool.h>

typedef struct node_s
{
    size_t x;
    size_t y;
    struct node_s *prev;
    struct node_s *next;
} node_t;

char **get_map_in_file(char **av);
char **get_map_on_input(void);
char **error_handling(char **map);
node_t *create_node(void);
node_t *add_node(int x, int y, node_t *node);
node_t *delete_last_node(node_t *node);
int new_algo(char **map, node_t *node, size_t info[2]);