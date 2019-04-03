/*
** EPITECH PROJECT, 2019
** solver
** File description:
** error_handling
*/

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include "my.h"
#include "my_stdio.h"
#include "my_string.h"
#include "dante.h"

char **error_handling(char **map)
{
    int arr_len = my_strarraylen(map);
    int oui = 0;
    size_t len = 0;

    if (arr_len == 0)
        return (NULL);
    len = strlen(map[0]);
    for (size_t i = 0; map[i] != NULL; i++) {
        if (strlen(map[i]) != len)
            return (NULL);
        for (size_t j = 0; j < len; j++)
            oui = ((map[i][j] != '*' && map[i][j] != 'X') ? 1 : oui);
    }
    if (oui == 1)
        return (NULL);
    if (map[0][0] != '*' || map[arr_len - 1][len - 1] != '*') {
        printf("no solution found");
        return (NULL);
    }
    return (map);
}