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
#include "generator.h"

int perfect_generation(size_t height, size_t width)
{
    char *map = malloc(height * width + height - 1);

    if (!map)
        return -1;
    memset(map, '#', height * width + height - 1);
    for (size_t i = 0; i < height - 1; i++)
        map[i + i * height + width] = '\n';
    for (size_t i = 0; i < height; i += 2) {
        for (size_t j = 0; j < width; j += 2)
            map[i + i * width + j] = '*';
    }
    write(1, map, height * width + height - 1);
    write(1, "\n", 1);
    free(map);
    return 0;
}
