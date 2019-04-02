/*
** EPITECH PROJECT, 2019
** CPE_dante_2018
** File description:
** generator
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

#define GET_NODE(node, x, y, width) node + x * width + y
#define INDEX_OF_WALL(cur_x, cur_y, x, y, width) (cur_x + (x - cur_x) / 2) * width + cur_y + (y - cur_y) / 2

enum directions_e {
	N = 0b0001,
	E = 0b0010,
	S = 0b0100,
	W = 0b1000
};

struct node_s {
	size_t x;
	size_t y;
	struct node_s *prev;
	char c;
	char directions;
};

struct node_s *init_map(size_t height, size_t width);
struct node_s *create_map(size_t height, size_t width);
void draw_map(struct node_s *nodes, size_t height, size_t width);
struct node_s *link_node(struct node_s *nodes, struct node_s *current,
								size_t height, size_t width);

#endif /* !GENERATOR_H_ */
