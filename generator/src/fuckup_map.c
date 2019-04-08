/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** fuckup_map
*/

#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

static void remove_wall(char *map, long i, long j, long w)
{
    if (map[MAP_NODE(i, j, w)] != 'X')
        return;
    if (map[MAP_NODE((i - 1), j, w)] != '*')
        return;
    if (map[MAP_NODE((i + 1), j, w)] != '*')
        return;
    if (map[MAP_NODE(i, (j - 1), w)] != 'X')
        return;
    if (map[MAP_NODE(i, (j + 1), w)] != 'X')
        return;
    map[MAP_NODE(i, j, w)] = '*';
}

void randomize_map_fuckup(char *map, long height, long width)
{
    if (!map)
        return;
    for (long i = 1; i < height - 1; i++) {
        for (long j = 1; j < width - 1; j++)
            remove_wall(map, i, j, width);
    }
}
