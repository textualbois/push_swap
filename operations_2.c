#include "push_swap.h"

t_stacknode *create_new_node(int value) {
	t_stacknode *node = malloc(sizeof(t_stacknode));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->is_top = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stacknode *add_node(int value) {
	t_stacknode *node = malloc(sizeof(t_stacknode));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->is_top = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}