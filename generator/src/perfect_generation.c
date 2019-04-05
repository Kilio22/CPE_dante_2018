/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** perfect_generation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "generator.h"

static int get_dig_direction(size_t i, size_t j)
{
    if (i && j)
        return rand() % 2;
    if (i)
        return NORTH;
    if (j)
        return WEST;
    return -1;
}

int dig_walls(char *map, size_t i, size_t width)
{
    int dir;

    for (size_t j = width - ((width % 2) ? 1 : 2); j < width; j -= 2) {
        dir = get_dig_direction(i, j);
        if (dir == -1)
            return 0;
        if (dir == NORTH)
            map[(i - 1) + (i - 1) * width + j] = '*';
        else if (dir == WEST)
            map[i + i * width + (j - 1)] = '*';
    }
    return 0;
}

static char *create_blank_maze(size_t height, size_t width)
{
    char *maze = malloc(MAP_SIZE(height, width));

    if (!maze)
        return NULL;
    memset(maze, 'X', MAP_SIZE(height, width));
    for (size_t i = 0; i < height - 1; i++)
        maze[i + i * width + width] = '\n';
    for (size_t i = 0; i < height; i += 2) {
        for (size_t j = 0; j < width; j += 2)
            maze[i + i * width + j] = '*';
    }
    return maze;
}

static struct map_s init_map(size_t height, size_t width)
{
    struct map_s map;
    char *maze = create_blank_maze(height, width);

    map.height = height;
    map.width = width;
    map.maze = maze;
    for (size_t i = 0; i < MAX_CHILDS; i++)
        map.nodes[i] = NULL;
    return map;
}

static struct node_s *create_node_map(size_t h, size_t w)
{
    struct node_s *node_map = malloc(sizeof(struct node_s) * MAP_SIZE(h, w));

    if (!node_map)
        return NULL;
    for (size_t i = 0; i < h; i += 2) {
        for (size_t j = 0; j < w; j += 2) {
            node_map[i + i * w + j].x = i;
            node_map[i + i * w + j].y = j;
            node_map[i + i * w + j].dir = 0b1111;
            node_map[i + i * w + j].prev = NULL;
        }
    }
    return node_map;
}

struct node_s *link_node(struct node_s *node)
{
    return node->prev;
}

void remove_child(struct node_s **nodes, size_t index, size_t child_nb)
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
        map->nodes[i] = link_node(map->nodes[i]);
    }
    return child_nb;
}

char *perfect_generation(size_t height, size_t width)
{
    struct map_s map = init_map(height, width);
    struct node_s *node_map = create_node_map(height, width);
    struct node_s *start = node_map;
    size_t child_nb = 1;

    if (!map.maze || !node_map)
        return NULL;
    start->prev = start;
    map.nodes[0] = link_node(start);
    while (child_nb)
        child_nb = build_maze(&map, start, child_nb);
    free(node_map);
    return map.maze;
}
