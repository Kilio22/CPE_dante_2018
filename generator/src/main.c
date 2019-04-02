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
#include "my_string.h"
#include "generator.h"

int main(int argc, char *argv[])
{
	size_t width;
	size_t height;

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
	perfect_generation(height, width);
	// if (STR_EQ(argv[4], "parfait"))
	// ;
	// else
	// ;
	return EXIT_SUCCESS;
}
