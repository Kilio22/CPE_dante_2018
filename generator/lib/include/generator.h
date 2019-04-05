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

enum directions {
	NORTH = 0b0001,
	EAST = 0b0010,
	SOUTH = 0b0100,
	WEST = 0b1000
};

struct node_s {
	size_t x;
	size_t y;
	char dir;
	struct node_s *prev;
};

struct map_s {
	size_t height;
	size_t width;
	char *maze;
	struct node_s *nodes[MAX_CHILDS];
};

#define STR_EQ(s1, s2) !strcmp(s1, s2)

char *perfect_generation(size_t height, size_t width);

#endif /* !GENERATOR_H_ */
