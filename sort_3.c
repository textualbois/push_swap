/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:40:27 by isemin            #+#    #+#             */
/*   Updated: 2024/06/16 18:40:28 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_stacknode **head)
{
	t_stacknode	*max_node;

	max_node = ft_max_val_node(*head);
	if (max_node == *head)
	{
		rotate(head);
		ft_putstr_fd("ra\n", 1);
	}
	if (max_node == (*head)->next)
	{
		rev_rotate(head);
		ft_putstr_fd("rra\n", 1);
	}
	if ((*head)->value > (*head)->next->value)
	{
		swap_top(head);
		ft_putstr_fd("sa\n", 1);
	}
}
