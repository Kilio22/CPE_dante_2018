/*
** EPITECH PROJECT, 2019
** solver
** File description:
** chained_lists
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "my_stdio.h"
#include "my_string.h"
#include "dante.h"

node_t *create_node(void)
{
    node_t *node = malloc(sizeof(node_t));

    node->x = 0;
    node->y = 0;
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

node_t *add_node(int x, int y, node_t *node)
{
    while (node->next != NULL)
        node = node->next;
    node->next = malloc(sizeof(node_t));
    node->next->x = x;
    node->next->y = y;
    node->next->prev = node;
    node->next->next = NULL;
    return (node);
}

node_t *delete_last_node(node_t *node)
{
    while (node->next != NULL)
        node = node->next;
    node = node->prev;
    node->next = NULL;
    return (node);
}