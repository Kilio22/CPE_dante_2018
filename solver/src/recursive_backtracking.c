/*
** EPITECH PROJECT, 2019
** solver
** File description:
** algo
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "my_stdio.h"
#include "my_string.h"
#include "dante.h"

int choose_bool(int i)
{
    if (i == 0)
        return (3);
    if (i == 1)
        return (2);
    if (i == 2)
        return (1);
    if (i == 3)
        return (0);
    return (0);
}

int choose_pos(int i, size_t *pos, bool *bools, size_t *size)
{
    if (bools[i] == true)
        return (-1);
    if (i == 0 && pos[1] + 1 < size[0]) {
        pos[1] += 1;
        return (0);
    }
    if (i == 1 && pos[0] + 1 < size[1]) {
        pos[0] += 1;
        return (0);
    }
    if (i == 2 && pos[0] > 0) {
        pos[0] -= 1;
        return (0);
    }
    if (i == 3 && pos[1] > 0) {
        pos[1] -= 1;
        return (0);
    }
    return (-1);
}

int algo(char **map, size_t pos[2], int prev, size_t *size)
{
    bool bools[4] = {false, false, false, false};
    size_t new_pos[2];

    bools[prev] = true;
    if (map[pos[0]][pos[1]] == 'X' || map[pos[0]][pos[1]] == 'o')
        return (-1);
    if (pos[0] == size[1] - 1 && pos[1] == size[0] - 1)
        return (0);
    map[pos[0]][pos[1]] = 'o';
    for (int i = 0; i < 4; i++) {
        new_pos[0] = pos[0];
        new_pos[1] = pos[1];
        if (choose_pos(i, new_pos, bools, size) == -1)
            continue;
        if (algo(map, new_pos, choose_bool(i), size) == 0)
            return (0);
    }
    map[pos[0]][pos[1]] = '*';
    return (-1);
}