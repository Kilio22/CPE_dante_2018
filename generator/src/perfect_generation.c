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

static char *init_map(size_t height, size_t width)
{
    char *map = malloc(height * width + height - 1);

    if (!map)
        return NULL;
    memset(map, 'X', height * width + height - 1);
    for (size_t i = 0; i < height - 1; i++)
        map[i + i * width + width] = '\n';
    for (size_t i = 0; i < height; i += 2) {
        for (size_t j = 0; j < width; j += 2)
            map[i + i * width + j] = '*';
    }
    return map;
}

char *perfect_generation(size_t height, size_t width)
{
    char *map = init_map(height, width);

    if (!map)
        return NULL;
    for (size_t i = height - ((height % 2) ? 1 : 2); i < height; i -= 2) {
        if (dig_walls(map, i, width) == -1)
            return NULL;
    }
    map[height * width + height - 2] = '*';
    if (!(height % 2 || width % 2)) {
        if (get_dig_direction(1, 1))
            map[height * width + height - 3] = '*';
        else
            map[height * width + height - 3 - width] = '*';
    }
    return map;
}
