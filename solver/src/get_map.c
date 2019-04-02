/*
** EPITECH PROJECT, 2019
** solver
** File description:
** get_map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my_string.h"
#include "my.h"
#include "my_stdio.h"

char **get_map_in_file(char **av)
{
    struct stat buf;
    char *buffer = NULL;
    char **array;
    int size = 0;
    int read_val = 0;
    int fd = open(av[1], O_RDONLY);

    if (fd == -1)
        return (NULL);
    if (stat(av[1], &buf) == -1)
        return (NULL);
    size = buf.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    if ((read_val = read(fd, buffer, size)) == -1)
        return (NULL);
    buffer[read_val] = '\0';
    array = my_str_towordarray(buffer, "\n");
    close(fd);
    free(buffer);
    return (array);
}

char **get_map_on_input(void)
{
    char **new = malloc(sizeof(char *) * 1);
    char *line = get_next_line(0);
    int i = 0;

    if (new == NULL)
        exit (84);
    new[0] = NULL;
    while (line) {
        new = my_realloc_array(new);
        new[i] = line;
        line = get_next_line(0);
        i++;
    }
    return (new);
}