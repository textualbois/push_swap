#include "push_swap.h"

void	insert_after(t_stacknode *dst, t_stacknode *new_node)
{
	if (dst != NULL)
	{
		add_before(dst->next, new_node);
		add_after(dst, new_node);
	}
}

void	insert_before(t_stacknode *dst, t_stacknode *new_node)
{
	if (dst != NULL)
	{
		add_after(dst->prev, new_node);
		add_before(dst, new_node);
	}
}

// void	insert_after(t_stacknode *dst, t_stacknode *new_node)
// {
// 	t_stacknode *right_hand_node;

// 	right_hand_node = dst->next;
// 	right_hand_node->prev = new_node;
// 	new_node->next = right_hand_node;
// 	dst->next = new_node;
// 	new_node->prev = dst;
// }

// void	insert_before(t_stacknode *dst, t_stacknode *new_node)
// {
// 	t_stacknode *left_hand_node;

// 	left_hand_node = dst->prev;
// 	left_hand_node->next = new_node;
// 	new_node->prev = left_hand_node;
// 	dst->prev = new_node;
// 	new_node->next = dst;
// }