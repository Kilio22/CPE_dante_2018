/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <string.h>

#define MAX_CHILDS 10
#define MAP_SIZE(h, w) (h * w + h - 1)
#define MAP_NODE(x, y, w) x + x * w + y
#define WALL_INDEX(nx, ny, x, y, width) (nx + (x - nx) / 2) + (nx + (x - nx) / 2) * width + (ny + (y - ny) / 2)

enum directions {
	NORTH = 0b0001,
	EAST = 0b0010,
	SOUTH = 0b0100,
	WEST = 0b1000
};

struct node_s {
	long x;
	long y;
	char dir;
	struct node_s *prev;
};

struct map_s {
	long height;
	long width;
	char *maze;
	struct node_s *node_map;
	struct node_s *nodes[MAX_CHILDS];
};

#define STR_EQ(s1, s2) !strcmp(s1, s2)

char *perfect_generation(long height, long width);
struct node_s *link_node(struct map_s *map, struct node_s *current);
long build_maze(struct map_s *map, struct node_s *start, long child_nb);

#endif /* !GENERATOR_H_ */
