#include "push_swap.h"

t_stacknode *create_new_node(int value)
{
	t_stacknode *node;
	
	node = malloc(sizeof(t_stacknode));
	if (node == NULL)
		return (NULL);
	node->value = value;
	node->is_top = 0;
	node->next = node;
	node->prev = node;
	return (node);
}

void	make_circular(t_stacknode *head, t_stacknode *last)
{
	add_before(head, last);
}

void	add_after(t_stacknode *current, t_stacknode *new)
{
	current->next = new;
	new->prev = current;
}

void	add_before(t_stacknode *current, t_stacknode *new)
{
	current->prev = new;
	new->next = current;
}
