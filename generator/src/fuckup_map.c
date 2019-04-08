/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** fuckup_map
*/

#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

static void remove_every_first_wall_line(char *map, long width)
{
    long j = 0;

    for (long i = 0; i < width; i++) {
        j = 0;
        while (j < width && map[MAP_NODE(i, j, width)] == '*')
            j++;
        if (j == width)
            continue;
        map[MAP_NODE(i, j, width)] = '*';
    }
}

static void remove_every_first_wall_colmun(char *map, long height, long width)
{
    long i = 0;

    for (long j = 0; j < width; j++) {
        i = 0;
        while (i < height && map[MAP_NODE(i, j, width)] == '*')
            i++;
        if (i == height)
            continue;
        map[MAP_NODE(i, j, width)] = '*';
    }
}

void randomize_map_fuckup(char *map, long height, long width)
{
    long n = (height * width) / 2;
    long x;
    long y;

    if (!map)
        return;
    while (n--) {
        x = rand() % 2
    }
}
