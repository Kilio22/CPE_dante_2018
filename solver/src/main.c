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

int print_map(char **map, size_t *size)
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

solver_t **init_solver(char **map)
{
    solver_t **solver = malloc(sizeof(solver_t *) * my_strarraylen(map));
    size_t arr_len = my_strarraylen(map);
    size_t len = strlen(map[0]);

    for (size_t i = 0; i < arr_len; i++) {
        solver[i] = malloc(sizeof(solver_t) * len);
        for (size_t j = 0; j < len; j++) {
            solver[i][j].size[0] = len;
            solver[i][j].size[1] = arr_len;
            solver[i][j].crossed = 0;
        }
    }
    return (solver);
}

int call_algo(char **map)
{
    size_t *pos = malloc(sizeof(size_t) * 2);
    solver_t **solver = init_solver(map);
    size_t *size = malloc(sizeof(size_t) * 2);

    size[0] = strlen(map[0]);
    size[1] = my_strarraylen(map);
    if (pos == NULL)
        exit(84);
    pos[0] = 0;
    pos[1] = 0;
    if (algo(map, pos, 2, solver) == -1) {
        map[size[1] - 1][size[0] - 1] = '*';
        return (-1);
    }
    else {
        map[size[1] - 1][size[0] - 1] = 'o';
        return (print_map(map, size));
    }
    for (size_t i = 0; i < pos[1]; i++)
        free(solver[i]);
    free(solver);
    return (0);
}

void init(void)
{
    struct rlimit oui;

    getrlimit(RLIMIT_STACK, &oui);
    oui.rlim_cur = STACK * (16 + (5000 / 8));
    setrlimit(RLIMIT_STACK, &oui);
}

int main(int ac, char **av)
{
    char **map = NULL;
    int ret_val = 0;

    if (ac > 2)
        return (84);
    init();
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
        printf("no solution found");
        return (84);
    }
    return (0);
}
