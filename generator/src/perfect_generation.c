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

static char *create_blank_maze(long height, long width)
{
    char *maze = malloc(MAP_SIZE(height, width));

    if (!maze)
        return NULL;
    memset(maze, 'X', MAP_SIZE(height, width));
    for (long i = 0; i < height - 1; i++)
        maze[i + i * width + width] = '\n';
    for (long i = 0; i < height; i += 2) {
        for (long j = 0; j < width; j += 2)
            maze[MAP_NODE(i, j, width)] = '*';
    }
    return maze;
}

static struct map_s init_map(long height, long width)
{
    struct map_s map;
    char *maze = create_blank_maze(height, width);

    map.height = height;
    map.width = width;
    map.maze = maze;
    for (long i = 0; i < MAX_CHILDS; i++)
        map.nodes[i] = NULL;
    return map;
}

static struct node_s *create_node_map(long h, long w)
{
    struct node_s *node_map = malloc(sizeof(struct node_s) * MAP_SIZE(h, w));
    long index;

    if (!node_map)
        return NULL;
    for (long i = 0; i < h; i += 2) {
        for (long j = 0; j < w; j += 2) {
            index = MAP_NODE(i, j, w);
            node_map[index].x = i;
            node_map[index].y = j;
            node_map[index].dir = 0b1111;
            node_map[index].prev = NULL;
        }
    }
    return node_map;
}

char *perfect_generation(long height, long width)
{
    struct map_s map = init_map(height, width);
    struct node_s *node_map = create_node_map(height, width);
    struct node_s *start = node_map;
    long child_nb = 1;

    if (!map.maze || !node_map)
        return NULL;
    map.node_map = node_map;
    start->prev = start;
    map.nodes[0] = link_node(&map, start);
    while (child_nb)
        child_nb = build_maze(&map, start, child_nb);
    // if (map.maze[MAP_NODE(height - 1, width - 1, width)] != '*')
        // map.maze[MAP_NODE(height - 1, width - 1, width)] = '*';
    free(node_map);
    return map.maze;
}
