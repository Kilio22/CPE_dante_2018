/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "my.h"
#include "my_stdio.h"
#include "my_string.h"
#include "dante.h"

int call_algo(char **map)
{
    size_t *pos = malloc(sizeof(size_t) * 2);
    int come_from = 2;
    int ret_val = 0;

    pos[0] = 0;
    pos[1] = 0;
    ret_val = algo(map, pos, come_from);
    if (ret_val == -1)
        map[my_strarraylen(map) - 1][strlen(map[0]) - 1] = '*';
    else
        map[my_strarraylen(map) - 1][strlen(map[0]) - 1] = 'o';
    for (int i = 0; map[i] != NULL; i++)
        printf("%s\n", map[i]);
    return (ret_val);
}

int main(int ac, char **av)
{
    char **map = NULL;
    int ret_val = 0;

    if (ac > 2)
        return (84);
    if (ac == 1)
        map = get_map_on_input();
    else
        map = get_map_in_file(av);
    if (map == NULL)
        return (84);
    map = error_handling(map);
    if (map == NULL)
        return (84);
    ret_val = call_algo(map);
    if (ret_val == -1) {
        puts("no solution found");
        return (84);
    }
    return (0);
}
