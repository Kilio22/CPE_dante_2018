/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** draw_map
*/

#include <stdio.h>
#include "generator.h"

void draw_map(struct node_s *nodes, size_t height, size_t width)
{
    struct node_s *ptr;
    size_t n_width = width % 2 ? width : width + 1;

    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < width; j++) {
            ptr = GET_NODE(nodes, i, j, n_width);
            putchar((i == height - 1 && j == width - 1) ? '*' : ptr->c);
        }
        putchar('\n');
    }
}
