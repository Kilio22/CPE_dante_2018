/*
** EPITECH PROJECT, 2019
** generator
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "generator.h"

int main(int argc, char *argv[])
{
	size_t width;
	size_t n_width;
	size_t height;
	size_t n_height;
	struct node_s *nodes;

	if (argc < 3)
		return 84;
	if (sscanf(argv[1], "%lu", &width) + sscanf(argv[2], "%lu", &height) < 2) {
		fprintf(stderr, "%s: invalid maze size values!\n", argv[0]);
		return 84;
	}
	if (width <= 0 || height <= 0) {
		fprintf(stderr, "%s: dimensions must be greater than 0!\n", argv[0]);
		return 84;
	}
	srand(time(NULL));
	n_height = height % 2 ? height : height + 1;
	n_width = width % 2 ? width : width + 1;
	nodes = create_map(n_height, n_width);
	if (nodes == NULL)
		return 84;
	draw_map(nodes, height, width);
	free(nodes);
	return EXIT_SUCCESS;
}
