/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:36:59 by isemin            #+#    #+#             */
/*   Updated: 2024/06/16 18:38:25 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_largest_pos(int *to_top, int *to_bottom, t_stacknode *head)
{
	t_stacknode	*current;
	int			max;
	int			count;

	current = head;
	max = current->value;
	*to_top = 0;
	count = 0;
	current = current->next;
	while (current->value < max && current != head)
	{
		count++;
		current = current->next;
	}
	if (current->value > max)
	{
		*to_top = count;
		count = 0;
	}
	while (current != head)
	{
		count++;
		current = current->next;
	}
	*to_bottom = count;
}

static void	get_smallest_pos(int *to_top, int *to_bottom, t_stacknode *head)
{
	t_stacknode	*current;
	int			min;
	int			count;

	current = head;
	min = current->value;
	*to_top = 0;
	count = 0;
	current = current->next;
	while (current->value > min && current != head)
	{
		count++;
		current = current->next;
	}
	if (current->value < min)
	{
		*to_top = count + 1;
		count = 0;
	}
	while (current != head)
	{
		count++;
		current = current->next;
	}
	*to_bottom = count;
}

void	reset_order_a(t_stacknode **head)
{
	int	to_top;
	int	to_bottom;

	if (head != NULL)
	{
		get_smallest_pos(&to_top, &to_bottom, *head);
		if (to_top <= to_bottom)
		{
			while (to_top > 0)
			{
				rotate(head);
				to_top--;
				write(1, "ra\n", 3);
			}
		}
		else
		{
			while (to_bottom >= 1)
			{
				rev_rotate(head);
				to_bottom--;
				write(1, "rra\n", 4);
			}
		}
	}
}

void	reset_order_b(t_stacknode **head)
{
	int	to_top;
	int	to_bottom;

	if (head != NULL)
	{
		get_largest_pos(&to_top, &to_bottom, *head);
		if (to_top <= to_bottom)
		{
			while (to_top >= 0)
			{
				rotate(head);
				to_top--;
				write(1, "rb\n", 3);
			}
		}
		else
		{
			while (to_bottom >= 1)
			{
				rev_rotate(head);
				to_bottom--;
				write(1, "rrb\n", 4);
			}
		}
	}
}