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
        return (1);
    if (i == 1)
        return (0);
    if (i == 2)
        return (3);
    if (i == 3)
        return (2);
    return (0);
}

void choose_pos(int i, int *pos, char **map, bool *bools)
{
    if (bools[i] == true)
        pos[0] = -1;
    if (i == 0)
        pos[0] += 1;
    if (i == 1)
        pos[0] -= 1;
    if (i == 2)
        pos[1] += 1;
    if (i == 3)
        pos[1] -= 1;
    if (pos[1] < 0 || pos[0] < 0 || pos[1] >= (int)my_strlen(map[0]) ||
pos[0] >= (int)my_strarraylen(map))
        pos[0] = -1;
}

int algo(char **map, int pos[2], int prev)
{
    bool bools[4] = {false, false, false, false};
    int n_val = -1;
    int new_pos[2];

    bools[prev] = true;
    if (map[pos[0]][pos[1]] == 'X' || map[pos[0]][pos[1]] == 'o')
        return (-1);
    if (map[pos[0]][pos[1]] == 'G')
        return (0);
    map[pos[0]][pos[1]] = 'o';
    for (int i = 0; i < 4; i++) {
        new_pos[0] = pos[0];
        new_pos[1] = pos[1];
        choose_pos(i, new_pos, map, bools);
        if (new_pos[0] == -1)
            continue;
        if ((n_val = algo(map, new_pos, choose_bool(i))) == 0)
            return (0);
    }
    map[pos[0]][pos[1]] = '*';
    return (-1);
}