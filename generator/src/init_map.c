/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** init_map
*/

#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

static void set_node_values(struct node_s *ptr, size_t i, size_t j)
{
	if (i % 2 == 0 && j % 2 == 0) {
		ptr->x = i;
		ptr->y = j;
		ptr->prev = NULL;
		ptr->c = '*';
		ptr->directions = 0b1111;
	} else
		ptr->c = 'X';
}

struct node_s *init_map(size_t height, size_t width)
{
	struct node_s *nodes = calloc(height * width, sizeof(struct node_s));

	if (nodes == NULL)
		return NULL;
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++)
			set_node_values(GET_NODE(nodes, i, j, width), i, j);
	}
	return nodes;
}
