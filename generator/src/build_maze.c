/*
** EPITECH PROJECT, 2019
** generator
** File description:
** build_maze
*/

#include "generator.h"

static void remove_child(struct node_s **nodes, size_t index, size_t child_nb)
{
    for (size_t i = index; i < child_nb - 1; i++)
        nodes[i] = nodes[i + 1];
}

size_t build_maze(struct map_s *map, struct node_s *start, size_t child_nb)
{
    for (size_t i = 0; i < child_nb; i++) {
        if (map->nodes[i] == start) {
            remove_child(map->nodes, i--, child_nb--);
            continue;
        }
        map->nodes[i] = link_node(map, map->nodes[i]);
    }
    return child_nb;
}
