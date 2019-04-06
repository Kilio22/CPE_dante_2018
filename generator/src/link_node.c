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
			return NORTH;
		case 1:
			return EAST;
		case 2:
			return SOUTH;
		case 3:
			return WEST;
	}
	return NORTH;
}

static size_t get_link_coordinates(struct map_s *map, struct node_s *current,
									char direction, long *x)
{
	long y = current->y;

	*x = current->x;
	if (direction == NORTH && current->x + 2 < map->width)
		*x = current->x + 2;
	if (direction == EAST && current->y + 2 < map->height)
		y = current->y + 2;
	if (direction == SOUTH && current->x - 2 >= 0)
		*x = current->x - 2;
	if (direction == WEST && current->y - 2 >= 0)
		y = current->y - 2;
	return y;
}

struct node_s *link_node(struct map_s *map, struct node_s *current)
{
	struct node_s *dest;
	char dir;
	long x;
	long y;

	while (current->dir) {
		dir = get_rand_direction();
		if (~current->dir & dir)
			continue;
		current->dir -= dir;
		y = get_link_coordinates(map, current, dir, &x);
		if (x == current->x && y == current->y)
			continue;
		dest = GET_NODE(nodes, x, y, width);
		if (dest->c != '*' || dest->prev)
			continue;
		dest->prev = current;
		map->maze[INDEX_OF_WALL(current->x, current->y, x, y, width)] = '*';
		return dest;
	}
	return current->prev;
}
