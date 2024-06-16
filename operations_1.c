/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isemin <isemin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:38:41 by isemin            #+#    #+#             */
/*   Updated: 2024/06/16 18:38:52 by isemin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacknode	*create_new_node(int value)
{
	t_stacknode	*node;

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
	if (current != NULL)
	{
		current->next = new;
		new->prev = current;
	}
}

void	add_before(t_stacknode *current, t_stacknode *new)
{
	if (current != NULL)
	{
		current->prev = new;
		new->next = current;
	}
}
