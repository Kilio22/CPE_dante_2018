/*
** EPITECH PROJECT, 2019
** solver
** File description:
** new_algo
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "my_stdio.h"
#include "my_string.h"
#include "dante.h"

int choose_map_pos(node_t **node, char **map, size_t info[2])
{
    if ((*node)->y + 1 < info[1] && map[(*node)->x][(*node)->y + 1] == '*') {
        *node = add_node((*node)->x, (*node)->y + 1, *node);
        return (0);
    }
    if ((*node)->x + 1 < info[0] && map[(*node)->x + 1][(*node)->y] == '*') {
        *node = add_node((*node)->x + 1, (*node)->y, *node);
        return (0);
    }
    if ((*node)->x > 0 && map[(*node)->x - 1][(*node)->y] == '*') {
        *node = add_node((*node)->x - 1, (*node)->y, *node);
        return (0);
    }
    if ((*node)->y > 0 && map[(*node)->x][(*node)->y - 1] == '*') {
        *node = add_node((*node)->x, (*node)->y - 1, *node);
        return (0);
    }
    map[(*node)->x][(*node)->y] = 'Q';
    return (-1);
}

int new_algo(char **map, node_t *node, size_t info[2])
{
    int n_val = 0;

    while (n_val == 0) {
        map[node->x][node->y] = 'o';
        if (node->x == info[0] - 1 && node->y == info[1] - 1)
            return (0);
        if (choose_map_pos(&node, map, info) == -1) {
            if (node->x == 0 && node->y == 0)
                return (-1);
            node = delete_last_node(node);
        }
        if (node->x == info[0] - 1 && node->y == info[1] - 1) {
            map[node->x][node->y] = 'o';
            return (0);
        }
    }
    return (0);
}