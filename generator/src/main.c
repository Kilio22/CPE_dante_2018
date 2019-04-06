/*
** EPITECH PROJECT, 2019
** generator
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "my.h"
#include "my_string.h"
#include "generator.h"

static void randomize_map_fuckup(char *map, long height, long width)
{
    long n = (height * width) / 2;
    long x;
    long y;

    if (!map)
        return;
    while (n--) {
        x = rand() % height;
        y = rand() % width;
        map[x + x * width + y] = '*';
    }
}

static int display_maze(char *map, long height, long width)
{
    if (!map)
        return 84;
    if (write(1, map, MAP_SIZE(height, width)) == -1)
        return 84;
    write(1, "\n", 1);
    free(map);
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    char *map;
    long width;
    long height;

    if (argc < 3)
        return 84;
    if (sscanf(argv[1], "%ld", &width) + sscanf(argv[2], "%ld", &height) < 2) {
        fprintf(stderr, "%s: invalid maze size values!\n", argv[0]);
        return 84;
    }
    if (width <= 0 || height <= 0) {
        fprintf(stderr, "%s: dimensions must be greater than 0!\n", argv[0]);
        return 84;
    }
    srand(time(NULL));
    map = perfect_generation(height, width);
    if (!(argc > 3 && STR_EQ(argv[3], "perfect")))
        randomize_map_fuckup(map, height, width);
    return display_maze(map, height, width);
}
