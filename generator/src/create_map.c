/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** create_map
*/

#include <stdlib.h>
#include "generator.h"

struct node_s *create_map(size_t height, size_t width)
{
	struct node_s *nodes = init_map(height, width);
	struct node_s *start;
	struct node_s *current;

	if (nodes == NULL)
		return NULL;
	start = nodes;
	start->prev = start;
	current = link_node(nodes, start, height, width);
	while (current != start)
		current = link_node(nodes, current, height, width);
	return nodes;
}
