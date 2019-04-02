/*
** EPITECH PROJECT, 2019
** solver
** File description:
** dante
*/

#pragma once

char **get_map_in_file(char **av);
char **get_map_on_input(void);
char **error_handling(char **map);
int algo(char **map, size_t pos[2], int prev);