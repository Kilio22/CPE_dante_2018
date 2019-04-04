/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main function
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "my.h"
#include "my_stdio.h"
#include "my_string.h"
#include "dante.h"

int print_map(char **map, size_t size[2])
{
    char *printaj = malloc(sizeof(char) * (size[0] * size[1] + size[0]));
    int j = 0;
    int oui = 0;

    for (int i = 0; map[i]; i++) {
        for (j = 0; map[i][j]; j++) {
            printaj[oui] = map[i][j];
            oui++;
        }
        if (map[i + 1] == NULL)
            printaj[oui] = '\0';
        else
            printaj[oui] = '\n';
        oui++;
    }
    write(1, printaj, strlen(printaj));
    free(printaj);
    for (int i = 0; map[i]; i++)
        free(map[i]);
    return (0);
}

int algo_to_do(char **map)
{
    size_t info[2] = {my_strarraylen(map), strlen(map[0])};
    node_t *head = create_node();

    if (new_algo(map, head, info) == -1)
        return (84);
    for (size_t i = 0; i < info[0]; i++) {
        for (size_t j = 0; j < info[1]; j++) {
            if (map[i][j] == 'Q')
                map[i][j] = '*';
        }
    }
    print_map(map, info);
    return (0);
}

int main(int ac, char **av)
{
    char **map = NULL;

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
    if (algo_to_do(map) == 84) {
        printf("no solution found");
        return (84);
    }
    return (0);
}
