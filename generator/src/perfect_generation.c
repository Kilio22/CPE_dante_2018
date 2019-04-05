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
    memset(map.nodes, 0, sizeof(struct node_s *) * MAX_CHILDS);
    return map;
}

static struct node_s *create_map_nodes(size_t h, size_t w)
{
    struct node_s *nodes = malloc(sizeof(struct node_s) * MAP_SIZE(h, w));

    if (!nodes)
        return NULL;
    for (size_t i = 0; i < h; i += 2) {
        for (size_t j = 0; j < w; j += 2) {
            nodes[i + i * w + j].x = i;
            nodes[i + i * w + j].y = j;
            nodes[i + i * w + j].dir = 0b1111;
            nodes[i + i * w + j].prev = NULL;
        }
    }
    return nodes;
}

char *perfect_generation(size_t height, size_t width)
{
    struct map_s map = init_map(height, width);
    struct node_s *nodes = create_map_nodes(height, width);

    if (!map.maze || !nodes)
        return NULL;
    free(map.maze);
    free(nodes);
    return NULL;
}
