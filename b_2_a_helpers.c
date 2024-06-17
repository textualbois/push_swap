/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_2_a_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:36:39 by isemin            #+#    #+#             */
/*   Updated: 2024/06/17 15:51:20 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_moves_2_a(t_stacknode *b_node, t_stacknode *a_head, \
						t_stacknode *b_head, int *moves)
{
	t_twoints	pos;
	t_twoints	len;
	int			res;

	get_b_node_pos(&(pos.b), &(len.b), b_node, b_head);
	get_a_node_insert(&(pos.a), &(len.a), b_node->value, a_head);
	*moves = int_max(pos.a, pos.b);
	res = BOTH_UP;
	if (int_max(len.a - pos.a + 1, len.b - pos.b + 1) < *moves)
	{
		*moves = int_max(len.a - pos.a + 1, len.b - pos.b + 1);
		res = BOTH_DOWN;
	}
	if ((pos.a + len.b - pos.b + 1) < *moves)
	{
		*moves = pos.a + len.b - pos.b + 1;
		res = A_UP_B_DOWN;
	}
	if ((len.a - pos.a + 1 + pos.b) <= *moves)
	{
		*moves = len.a - pos.a + 1 + pos.b;
		res = A_DOWN_B_UP;
	}
	return (res);
}

void	get_b_node_pos(int *pos, int *len, t_stacknode *node, t_stacknode *head)
{
	t_stacknode	*current;

	*pos = 0;
	*len = 0;
	current = head;
	while (current != node)
	{
		*pos = *pos + 1;
		*len = *len + 1;
		current = current->next;
	}
	while (current->next != head)
	{
		*len = *len + 1;
		current = current->next;
	}
}

void	get_a_node_insert(int *pos, int *len, int value, t_stacknode *head)
{
	t_stacknode	*current;
	int			got_pos;

	got_pos = false;
	*pos = 0;
	*len = -1;
	current = head;
	if (head != NULL)
	{
		check_a_insert_pos(value, current->value, \
						current->prev->value, &got_pos);
		current = increment_all(pos, len, got_pos, current);
		while (current != head)
		{
			check_a_insert_pos(value, current->value, \
						current->prev->value, &got_pos);
			current = increment_all(pos, len, got_pos, \
									current);
		}
	}
	if (got_pos == false)
		get_pos_alt_2_a(pos, head);
}

void	get_pos_alt_2_a(int *pos, t_stacknode *head)
{
	t_stacknode	*current;
	int			smallest;
	int			index;

	index = 0;
	*pos = index;
	if (head != NULL)
	{
		smallest = head->value;
		current = head->next;
		while (current != head)
		{
			index++;
			if (current->value < smallest)
			{
				*pos = index;
				smallest = current->value;
			}
			current = current->next;
		}
	}
}
