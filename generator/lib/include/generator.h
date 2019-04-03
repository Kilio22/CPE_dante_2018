/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#include <string.h>

enum directions {
	NORTH,
	WEST
};

#define STR_EQ(s1, s2) !strcmp(s1, s2)

char *perfect_generation(size_t height, size_t width);

#endif /* !GENERATOR_H_ */
