#include "push_swap.h"

void	insert_after(t_stacknode *current, t_stacknode *new)
{
	current->next->prev = new;
	current->next = new;
	new->prev = current;
}

void	insert_before(t_stacknode *current, t_stacknode *new)
{
	current->prev->next = new;
	current->prev = new;
	new->next = current;
}
