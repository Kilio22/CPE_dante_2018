/*
** EPITECH PROJECT, 2019
** solver
** File description:
** dante
*/

char **get_map_in_file(char **av);
char **get_map_on_input(void);
int algo(char **map, int *pos, int come_from);
char **error_handling(char **map);