/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** link_map_nodes
*/

#include <stdlib.h>
#include <stdio.h>
#include "generator.h"

int get_rand_direction(void)
{
	switch (rand() % 4) {
		case 0:
			return N;
		case 1:
			return E;
		case 2:
			return S;
		case 3:
			return W;
	}
	return N;
}

static size_t *get_link_coordinates(struct node_s *current, char direction,
									size_t height, size_t width)
{
	static size_t coords[2];

	coords[0] = current->x;
	coords[1] = current->y;
	if (direction == N && current->x + 2 < width)
		coords[0] = current->x + 2;
	if (direction == E && current->y + 2 < height)
		coords[1] = current->y + 2;
	if (direction == S && current->x - 2 < current->x)
		coords[0] = current->x - 2;
	if (direction == W && current->y - 2 < current->y)
		coords[1] = current->y - 2;
	return coords;
}

struct node_s *link_node(struct node_s *nodes, struct node_s *current,
								size_t height, size_t width)
{
	struct node_s *dest;
	size_t *coords;
	char direction;

	while (current->directions) {
		direction = get_rand_direction();
		if (~current->directions & direction)
			continue;
		current->directions -= direction;
		coords = get_link_coordinates(current, direction, height, width);
		if (coords[0] == current->x && coords[1] == current->y)
			continue;
		dest = GET_NODE(nodes, coords[0], coords[1], width);
		if (dest->c != '*' || dest->prev)
			continue;
		dest->prev = current;
		nodes[INDEX_OF_WALL(current->x, current->y, coords[0],
coords[1], width)].c = '*';
		return dest;
	}
	return current->prev;
}
