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
									char dir, size_t *x)
{
	size_t y = current->y;

	*x = current->x;
	if (dir == EAST && current->y + 2 < map->height)
		return current->y + 2;
	else if (dir == WEST && current->y - 2 < current->y)
		return current->y - 2;
	if (dir == NORTH && current->x + 2 < map->width)
		*x = current->x + 2;
	else if (dir == SOUTH && current->x - 2 < current->x)
		*x = current->x - 2;
	return y;
}

struct node_s *link_node(struct map_s *map, struct node_s *current)
{
	struct node_s *dest;
	char dir;
	size_t x;
	size_t y;

	printf("\nENTERING %lu %lu NODE\n\n", current->x, current->y);
	while (current->dir) {
		dir = get_rand_direction();
		if (~current->dir & dir)
			continue;
		current->dir -= dir;
		y = get_link_coordinates(map, current, dir, &x);
		if (x == current->x && y == current->y)
			continue;
		dest = MAP_NODE(map->node_map, x, y, map->width);
		if (*(MAP_NODE(map->maze, x, y, map->width)) != '*' || dest->prev)
			continue;
		printf("Current x y : %lu %lu\nDest x y : %lu %lu\nWidth : %lu\n", current->x, current->y, x, y, map->width);
		printf("%lu\n", WALL_INDEX(current->x, current->y, x, y, map->width));
		map->maze[WALL_INDEX(current->x, current->y, x, y, map->width)] = '*';
		return dest;
	}
	return current->prev;
	// nodes[n->x + (x - n->x) / 2 + (n->y + (y - n->y) / 2) * width].c = ' ';
}
